#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int handle_redirect (char *argv[]);
int main(int argc, char *argv[]) {
	int True = 1;
	int False = 0;
	int check = True;
	if (argc > 1) {
		if (freopen(argv[1], "r", stdin) == NULL) {
			fprintf (stderr , "cant read your fucking file %s\n",argv[1]);
			exit(1);
		}
		check=False;
	}
	while (True) {
		char buffer[1024];
		// Print a prompt and read input from the user

		if (check) printf("$ ");
		if (fgets(buffer, 1024, stdin) == NULL) break;

		char *nl = strchr(buffer, '\n');
		if (nl) *nl = '\0';

		//remove comment
		char *comment = strchr(buffer, '#');
		if (comment) *comment = '\0';

		//split but info args
		int i = 0;
		char *args[64];
		args[i] = strtok(buffer, " ");
		while (args[i] != NULL) {
			args[++i] = strtok(NULL, " ");
		}
		if (args[0] == NULL) continue;
		if (strcmp (args[0] , "exit" ) == 0) exit(0);
		// Fork a child process
		pid_t pid = fork();
		if (pid > 0) {	
			wait(NULL);
		} else {
				if (handle_redirect(args) == -1) {
					fprintf(stderr, "could not redirect\n");
					exit(1);
				}
			execvp(args[0], args);
			perror("Error executing command");
			exit(1);
		}
	}

}
int handle_redirect (char *args[]) {
	for (int i = 0 ; args[i] != NULL; i++){
		if ( strcmp(args[i] , ">") == 0) {
			stdout = freopen (args[i+1],"w",stdout);
			if (stdout == NULL) return -1;
			args[i] = NULL;

			return 1;
		}
	}
}