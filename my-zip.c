//help for files: https://www.google.com/search?client=firefox-b-d&q=c+EOF
//zip: https://www.geeksforgeeks.org/c-program-to-read-and-print-all-files-from-a-zip-file/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if files are provided
    if (argc < 2) {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    // Process each file
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        // Check if the file can be opened
        if (file == NULL) {
            fprintf(stderr, "my-zip: cannot open file\n");
            exit(1);
        }

        int count = 0;
        char previous;
        char current;

        // Read the file 
        while ((current = fgetc(file)) != EOF) {
            if (count == 0) {
                // First character in a run
             previous = current;
                count = 1;
            } else if (current == previous) {
                // Same character, increment the count
                count++;
            } else {
                // Different character, write the run to stdout
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&previous, sizeof(char), 1, stdout);

                previous = current;
                count = 1;
            }
        }

        fclose(file);
    }

    return 0;
}