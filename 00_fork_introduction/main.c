#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t i;
    i = fork();

    // fork() returns a negative value if the creation of child process was unsuccessful.
    if (i == -1) {
        fprintf(stderr, "Process creation failed.\n");
        exit(1);
    }

    // fork() returns 0 to the child process.
    if (i == 0) {
        printf("(child): my process PID: %d\n", getpid());
        printf("(child): parent process PID: %d\n", getppid());
        exit(0);
    
    // fork() returns a positive value to the parent process.
    } else {
        printf("(parent): parent process PID: %d\n", getpid());
        printf("(parent): child process PID: %d\n", i);
        exit(0);
    }

    return 0;

}