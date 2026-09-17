#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char *argv[]){
    if (argc > 1){
        for (int i = 1;argc > i;i++){
            int file = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC , 0666);
            
            if (file < 0) {
                perror("touch");
                break;
            }
            close(file);
        }
    }
}