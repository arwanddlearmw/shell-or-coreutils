
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
int mk_dir(char *path) {
    char *s = path;

    if (*s == '/') s++;

    while (*s != '\0') {
        if (*s == '/') {
            *s = '\0'; 
            int status = mkdir(path, 0700);

            *s = '/'; 

            if (status != 0 && errno != EEXIST) {
                perror("mkdir");
                return 1;
            }
        }
        s++;
    }

    if (mkdir(path, 0700) != 0 && errno != EEXIST) {
        perror("mkdir");
        return 1;
    }

    return 0;
}

int main(int argc,char *argv[]){
    int opt;
    int check = 0;
    char *target_file;
    while ((opt = getopt(argc, argv, "p:")) != -1){
        switch (opt){
            case 'p':
                target_file = optarg;
                check = 1;
                break;

        }
    }
    if (check == 1){
        mk_dir(target_file);
    }else {
        for (int i =optind ; i < argc ; i++){
            if (mkdir(argv[i],0700) == -1){
                perror("mkdir");
                return 1;
            }
        }
    }
    return 0;
}