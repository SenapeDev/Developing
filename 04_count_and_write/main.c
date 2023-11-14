#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 100

void *count_char(void *p) {
    
    // ppen the file
    FILE *file = fopen((char *)p, "r");

    // verify if file exists
    if (file == NULL) {
        printf("Error during file opening.\n");
        return NULL;
    }

    // allocate memory for the result
    int *count = malloc(sizeof(int));
    if (count == NULL) {
        printf("Error during memory allocation.\n");
        fclose(file);
        return NULL;
    }

    // count the number of letters
    int letter = 0;
    *count = 0;

    while ((letter = fgetc(file)) != EOF) {
        (*count)++;
    }

    fclose(file);

    // return the result
    return count;
}

int main() {
    
    // create a thread ID
    pthread_t t_ID;

    // create a pointer to the result
    void *count_result;

    // allocate memory for the file name
    char *file_name = malloc(MAX_LEN * sizeof(char));

    // verify if the memory has been allocated
    if (file_name == NULL) {
        fprintf(stderr, "Error during memory allocation.");
        exit(EXIT_FAILURE);
    }

    // read file name
    printf("Inserisci il nome del file: ");
    fgets(file_name, MAX_LEN, stdin);

    // remove the newline character
    file_name[strcspn(file_name, "\n")] = '\0';

    // create the thread and pass the file name as argument
    pthread_create(&t_ID, NULL, &count_char, (void *)file_name);

    // wait for the thread to finish
    pthread_join(t_ID, &count_result);

    // print the result
    if (count_result != NULL) {
        printf("Numero di lettere: %d\n", *(int *)count_result);

        // free the memory
        free(count_result);
    }

    // free the memory
    free(file_name);

    return 0;
}
