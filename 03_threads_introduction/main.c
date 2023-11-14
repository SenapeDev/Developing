#include <stdio.h>
#include <pthread.h>

void *print_char(void *p) {

    // cast the void pointer to an int pointer
    int* ARGS;
    ARGS = (int *) p;

    // print the character
    for(int i=0; i<ARGS[1]; i++) {
        printf("%c\n", ARGS[0]);
        fflush(stdout);
    }

    return NULL;
}

int main() {

    // create a thread
    pthread_t t_ID;

    // get user input
    int repetitions, character;

    printf("Enter a single character: ");
    character = getchar();

    printf("How the number of repetition for letter '%c': ", character);
    scanf("%d", &repetitions);

    // create a pointer to an array of arguments
    int ARGS[2] = {character, repetitions};

    // create a thread
    pthread_create(&t_ID, NULL, &print_char, &ARGS);
    
    // wait for the thread to finish
    pthread_join(t_ID, NULL);

    return 0;

}