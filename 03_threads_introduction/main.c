#include <stdio.h>
#include <pthread.h>

void *print_char(void *p) {

    int* ARGS;
    ARGS = (int *) p;

    for(int i=0; i<ARGS[1]; i++) {
        printf("%c\n", ARGS[0]);
        fflush(stdout);
    }

    return NULL;

}

int main() {

        pthread_t t_ID;
        int repetitions, character;

        printf("Enter a single character: ");
        character = getchar();

        printf("How the number of repetition for letter '%c': ", character);
        scanf("%d", &repetitions);

        int ARGS[2] = {character, repetitions};

        pthread_create(&t_ID, NULL, &print_char, &ARGS);
        pthread_join(t_ID, NULL);

}