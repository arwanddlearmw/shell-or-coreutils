#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
int main(int argc, char *argv[]){
    struct stat check;
    if (argc > 2){
        if (stat(argv[1], &check) != 0) {
            perror("");
            return 1;
        }
        if (rename(argv[1],argv[2]) == 0){
            return 0;
        } else if (errno == EXDEV) {
            if (S_ISDIR(check.st_mode)){
                fprintf(stderr,"sorry but we dont support directory from anther filesystem.");
                return 1;
            }else {
                    int file_source = open(argv[1],O_RDONLY);
                    if (file_source < 0){
                        printf("the file could not open %s \n", argv[1]);
                        return 1;
                    }
                    int file_copy = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
                    if (file_copy < 0){
                        printf("the file could not open %s \n", argv[2]);
                        close(file_source);
                        return 1;

                    }
                    char buf[1024];
                    int status;
                    while ((status = read(file_source, buf, sizeof(buf))) > 0 ) {
                        write(file_copy, buf, status);
                    }
                    close(file_source);
                    close(file_copy);
                    remove (argv[1]);
                    return 0;
            }
        }else {
            perror("");
            return 1;
        }
    }
}