#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/param.h>
#include <unistd.h>


int main(int argc,char *argv[]){
    int file_source;
    int file_copy;
    char buf[1024];
    int status;
    if (argc>2){
        file_source = open(argv[1],O_RDONLY);
        if (file_source < 0){
            printf("the file could not open %s \n", argv[1]);
            return 1;
        }
        file_copy = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
        if (file_copy < 0){
            printf("the file could not open %s \n", argv[2]);
            return 1;
        }
        while ((status = read(file_source, buf, sizeof(buf))) > 0 ) {
            write(file_copy, buf, status);
        }
        close(file_source);
        close(file_copy);
        printf("Done.\n");
    }else {
        printf("u need the path file to copy \n");
    }
}
