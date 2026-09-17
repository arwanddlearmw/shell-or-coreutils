#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    long size; 
    char *buf; 
    char *ptr; 
    size = pathconf(".", _PC_PATH_MAX);
    buf = (char *)malloc((size_t)size);
    ptr = getcwd(buf, (size_t)size);
    printf("%s\n",ptr);
    free(buf);
}