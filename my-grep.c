//Looked for help to implementation: https://stackoverflow.com/questions/64503993/how-to-find-out-if-a-word-is-inside-of-a-line
// ssize_t: https://jameshfisher.com/2017/02/22/ssize_t/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    //error handling when no file is given
    if (argc <= 2) {
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    }
    
    //initialiate word looking for
    char *searched = argv[1];

    //Handle different amount of files
    if (argc < 3) {
        // Read from standard input and set initiate needed variables
        char *line = NULL;
        size_t length = 0; //for size of line
        ssize_t read; //for negative values

        //read and print lines 
        while ((read =getline(&line, &length, stdin)) != -1) {
            if (strstr(line, searched) != NULL) {
                printf("%s", line);
            }
        }
        free(line);

    } else {
        //loop through files
        for (int i = 2; i < argc; i++) {
            //try to open file
            FILE *file = fopen(argv[i], "r");

            //error handling fore file opening
            if (file == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
            }

            //initialation of line 
            char *line = NULL;
            size_t length = 0; //for size of line
            ssize_t read; //for negative values

            //read and print lines 
            while ((read =getline(&line, &length, file)) != -1) {
                //Check if word is in file
                if (strstr(line, searched) != NULL) {
                printf("%s", line);
                }
            }
            free(line);

            //close file
            fclose(file);
        }

    }

    return 0;
}