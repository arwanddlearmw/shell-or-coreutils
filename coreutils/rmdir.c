#include <unistd.h>
#include <stdio.h>

int main (int argc , char * argv[]) {
    
    if (argc >1){
        for (int i =1 ; i < argc ; i++){
            if (rmdir(argv[i]) == -1){
                perror("rmdir:");
            }
        }
    }else {
        printf("rm: pls type a path");
    }
}