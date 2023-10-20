#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {

    char *input_file = argv[0];
    char *output_file = argv[1];

    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    char **words = NULL;
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(input, "%s", word) == 1) {
        words = (char **)realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words] = strdup(word);
        num_words++;
    }

    fclose(input);

    qsort(words, num_words, sizeof(char *), compare);

    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(output);
    free(words);

    return 0;
}