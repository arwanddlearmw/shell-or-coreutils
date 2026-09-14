#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
struct stat st = {0};
int main(int argc,char *argv[]){
    if (argc >1){
        if (stat(argv[1], &st) == -1){
            mkdir(argv[1], 0700);
        }
    }else printf ("pls type a path \n");
}