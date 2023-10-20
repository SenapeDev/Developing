#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char* INPUT = argv[0];
    char* OUTPUT = argv[1];

    int c;
    FILE *file;
    file = fopen(INPUT, "r");
    
    if (file) {
        while ((c = getc(file)) != EOF) putchar(c);
        fclose(file);
    }

    

    
    return 0;
}