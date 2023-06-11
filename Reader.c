#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readStringsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    char** strings = NULL;
    char line[100];  // Assuming a maximum line length of 100 characters

    int numStrings = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Trim newline character from the line
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Reallocate memory for the array of strings
        strings = realloc(strings, (numStrings + 1) * sizeof(char*));
        if (strings == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }

        // Allocate memory for the current string and copy the line
        strings[numStrings] = malloc((strlen(line) + 1) * sizeof(char));
        if (strings[numStrings] == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }
        strcpy(strings[numStrings], line);

        numStrings++;
    }

    fclose(file);
    return strings;
}
