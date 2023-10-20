#include <stdio.h>
#include <string.h>

// struct student with name, surname and position
struct student {
    char name[100];
    char surname[100];
    int position;
};

int main(int argc, char *argv[]) {

    // if number of arguments is not 2, exit
    if (argc != 2) {
        printf("Usage: ./sort <input_file> <output_file>\n");
        return 1;
    }

    // name of input and output file
    char* INPUT = argv[0];
    char* OUTPUT = argv[1];

    // open file
    int c;
    FILE *file;
    file = fopen(INPUT, "r");
    
    // get number of lines in file
    int lines = 0;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }

    // add 1 to lines, because last line doesn't end with '\n'
    lines++;

    // create array of students
    struct student students[lines];

    // rewind file in order to read it again
    rewind(file);

    // read file and fill array
    int i = 0;

    // read 'name \t surname'; position auto increment starting from 1
    while (fscanf(file, "%s\t%s", students[i].name, students[i].surname) != EOF) {
        students[i].position = i + 1;
        i++;
    }
    
    // close file after reading
    fclose(file);

    // sort array of students by their name, using bubble sort
    for (int i = 0; i <= lines - 1; i++) {
        for (int j = 0; j <= lines - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // open output file in write mode
    FILE *output;
    output = fopen(OUTPUT, "w");

    // write sorted array of students in output file; format 'name \t surname'
    for (int i = 0; i < lines; i++) {
        fprintf(output, "%s\t%s\n", students[i].name, students[i].surname);
    }

    // close output file after writing
    fclose(output);

    return 0;
}