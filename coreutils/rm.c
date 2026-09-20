#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int remove_directory(const char *path) {
    struct stat path_stat;
    if (lstat(path,&path_stat) != 0) {
        perror("rm");
        return -1;
    }
    if (S_ISREG(path_stat.st_mode)){
        if (remove (path)){
            perror ("rm");
            return -1;
        }
        return 0;
    }else if (S_ISLNK(path_stat.st_mode)){
        if (unlink (path)){
            perror ("rm");
            return -1;
        }
        return 0;
    }
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;
        r = 0;
        while (!r && (p = readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2;
            buf = malloc(len);

            if (buf) {
                struct stat statbuf;
                snprintf(buf, len, "%s/%s", path, p->d_name);

                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                        r2 = remove_directory(buf);
                    else
                        r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }

    if (!r)
        r = rmdir(path);

    return r;
    
}

int main(int argc, char *argv[]) {
    int opt;
    char *target_path = NULL;
    int is_recursive = 0;
    if (argc < 2){
        fprintf(stderr, "pls type a file \n");
        return 1;
    }
    while ((opt = getopt(argc, argv, "r")) != -1) {
        switch (opt) {
            case 'r':
                is_recursive = 1;
                break;
            default:
                return 1;
        }
        
        
    }
    if (is_recursive){
        for (int i=optind;i < argc ; i++){
            if ((remove_directory(argv[i])) == -1) {
                perror("rm");
                return 1;
            }
        }
    }else {
        for (int i =optind ; i < argc ; i++){
            if (remove(argv[i]) == -1){
                perror("rm");
                return 1;
            }
        }
    }
    return 0;
}
