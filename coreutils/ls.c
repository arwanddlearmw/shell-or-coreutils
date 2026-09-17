#include <stdio.h>
#include <dirent.h>
#include <unistd.h>


int main(int argc , char *argv[]){

    DIR *dir = opendir(".");
    struct dirent *list; 

    while ((list = readdir(dir)) != NULL){
        printf("%s \n",list->d_name);
    }
    closedir(dir);
}