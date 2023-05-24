#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if files are provided
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    // Process each file
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        // Check if the file can be opened
        if (file == NULL) {
            printf("my-unzip: cannot open file\n");
            exit(1);
        }

        int count;
        char character;

        // Read the file
        while (fread(&count, sizeof(int), 1, file) == 1 && fread(&character, sizeof(char), 1, file) == 1) {
            // Print all the charachters
            for (int j = 0; j < count; j++) {
                printf("%c", character);
            }
        }

        fclose(file);
    }

    return 0;
}