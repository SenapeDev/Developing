#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// name of input and output file
char* INPUT_FILE = "text.txt";
char* OUTPUT_FILE = "sorted.txt";

int main() {

    pid_t i;
    i = fork();

    // wait for child process to finish
    int w;

    if (i == -1) {
        fprintf(stderr, "Process creation failed.\n");
        exit(1);
    }

    if (i == 0) {
        char* args[] = {INPUT_FILE, OUTPUT_FILE, NULL};
        execvp("./sort", args);
        exit(0);
    } else {
        w = wait(NULL);
        printf("File sorted successfully.\n");
        exit(0);
    }


    return 0;
}