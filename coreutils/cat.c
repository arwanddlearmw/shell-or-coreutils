#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[]) {
    if (argc > 1){
        for (int i=1 ; i < argc;i++){
            FILE *file=freopen(argv[i], "r",stdin);
        
            if (file == NULL) {
                perror("the file isnt found");
                exit(0);
            }
            char ch;
            while ( (ch = fgetc(file) ) != EOF ){
		        putchar(ch );
            }
            fclose(file);
        }
    }
    else {
        printf("pls enter the file input");
    }
    printf("\n");
}