#include <unistd.h>
#include <stdio.h>

int main (int argc , char * argv[]) {
    
    if (argc >1){
        for (int i =1 ; i < argc ; i++){
            if (remove(argv[i]) == -1){
                perror("rm:");
            }
        }
    }else {
        printf("rm: pls type a path");
    }
}