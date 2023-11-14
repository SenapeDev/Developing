#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 100

void *count_char(void *p) {
    // Apri il file
    FILE *file = fopen((char *)p, "r");

    // Verifica se il file esiste
    if (file == NULL) {
        printf("Errore durante l'apertura del file.\n");
        return NULL;
    }

    // Alloca memoria per count
    int *count = malloc(sizeof(int));
    if (count == NULL) {
        printf("Errore durante l'allocazione della memoria.\n");
        fclose(file);
        return NULL;
    }

    // Conta i caratteri
    int letter = 0;
    *count = 0;

    while ((letter = fgetc(file)) != EOF) {
        (*count)++;
    }

    fclose(file);

    // Restituisci count
    return count;
}

int main() {
    // Create a thread ID
    pthread_t t_ID;

    // Create a pointer to the result
    void *count_result;

    // Allocate memory for the file name
    char *file_name = malloc(MAX_LEN * sizeof(char));

    // Verify if the memory has been allocated
    if (file_name == NULL) {
        fprintf(stderr, "Error during memory allocation.");
        exit(EXIT_FAILURE);
    }

    // Read file name
    printf("Inserisci il nome del file: ");
    fgets(file_name, MAX_LEN, stdin);

    // remove the newline character
    file_name[strcspn(file_name, "\n")] = '\0';

    // Create the thread and pass the file name as argument
    pthread_create(&t_ID, NULL, &count_char, (void *)file_name);

    // Wait for the thread to finish
    pthread_join(t_ID, &count_result);

    // Print the result
    if (count_result != NULL) {
        printf("Numero di lettere: %d\n", *(int *)count_result);

        // free the memory
        free(count_result);
    }

    // free the memory
    free(file_name);

    return 0;
}
