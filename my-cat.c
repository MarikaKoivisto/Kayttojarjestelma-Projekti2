
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    //error handling when no file is given
    if (argc == 1) {
        exit(0);
    }

    //loop through file
    for (int i = 1; i < argc; i++) {
        //try to open file
        FILE *file = fopen(argv[i], "r");

        //error handling fore file opening
        if (file == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }

        //initialation of line 
        char line[256];

        //read and print lines 
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }

        //close file
        fclose(file);
    }

    return 0;
}