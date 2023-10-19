#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t i;
    i = fork();

    // used to wait for state changes in a child of the calling process.
    int w;

    // if fork() returns -1, an error happened.
    if (i == -1) {
        fprintf(stderr, "Process creation failed.\n");
        exit(1);
    }

    // if fork() returns 0, then it's the child process.
    if (i == 0) {
        printf("(child): I'm the child and I'm waiting 3 seconds.\n");
        printf("(child): ");

        // fflush() is used for printing the output immediately and not waiting for the buffer to get filled.
        fflush(stdout);
        for (int j=0; j<3; j++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n(child): My job is done.\n");
        exit(0);
    
    // if fork() returns a positive number, then it's the parent process.
    } else {
        printf("(parent): I'm the parent and I'm waiting for my child to finish.\n");
        
        // wait() the end of the child process.
        w = wait(NULL);
        printf("(parent): My child has finished.\n");
        exit(0);
    }

    return 0;

}