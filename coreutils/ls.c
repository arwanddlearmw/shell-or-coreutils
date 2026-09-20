#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc , char *argv[]){
    int hide_files = 1;
    int details = 0;
    char *target_dir = ".";
    DIR *dir;
    struct dirent *list;
    struct stat file_stat; 
    int opt;

    while ((opt = getopt(argc, argv, "la")) != -1) {
        switch (opt) {
            case 'a':
                target_dir = optarg; 
                hide_files = 0;
                break;
            case 'l':
                target_dir = optarg;
                details = 1; 
                break;
            default:
                break;
        }
    }

    if (optind < argc && argv[optind] != NULL) {
    target_dir = argv[optind];
    }

    if (target_dir == NULL) {
    target_dir = ".";
    }

    if ((dir = opendir(target_dir)) == NULL) {
        perror("opendir error");
        return 1;
    }
    while ((list = readdir(dir)) != NULL){
        printf ("\e[0m"); //reset the color to white
        if (hide_files){
            if (!strcmp(list->d_name, ".") || !strcmp(list->d_name, "..")){
                continue;
            }
            if ((list->d_name[0]) == '.'){
                continue;
            }
            
        }
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", target_dir, list->d_name);
        if (stat(full_path,&file_stat) == -1){
            perror("");
            return -1;
        }
        if (details){
            //dir
            putchar("d-"[!(S_ISDIR(file_stat.st_mode))]);
            //user permmision
            putchar("r-"[!(file_stat.st_mode & S_IRUSR)]);
            putchar("w-"[!(file_stat.st_mode & S_IWUSR)]);
            putchar("x-"[!(file_stat.st_mode & S_IXUSR)]);

            //grop perrmision
            putchar("r-"[!(file_stat.st_mode & S_IRGRP)]);
            putchar("w-"[!(file_stat.st_mode & S_IWGRP)]);
            putchar("x-"[!(file_stat.st_mode & S_IXGRP)]);
            //other permmision
            putchar("r-"[!(file_stat.st_mode & S_IROTH)]);
            putchar("w-"[!(file_stat.st_mode & S_IWOTH)]);
            putchar("x-"[!(file_stat.st_mode & S_IXOTH)]);
            //print users
            struct passwd *user = getpwuid(file_stat.st_uid);
            struct group *group = getgrgid(file_stat.st_gid);
            printf (" %s ",user ->pw_name);
            printf ("%s",group ->gr_name);
            //print last active file time
            char *time_str = ctime(&file_stat.st_ctime);
            time_str[strlen(time_str) - 1] = '\0';
            printf(" %s ",time_str);
        }
        if ((S_ISDIR(file_stat.st_mode))){
            printf ("\e[0;31m%s \n",list->d_name); //print red color
            continue;
        }else if (file_stat.st_mode & S_IXUSR || file_stat.st_mode & S_IXGRP || file_stat.st_mode & S_IXOTH){
            printf ("\e[0;34m %s \n",list->d_name);
            continue;
        }else if ((file_stat.st_mode)){
            printf ("%s \n",list->d_name); //print a normal color
            continue;
        }
        
    }
    printf ("\n");
    closedir(dir); 
    return 0;
}