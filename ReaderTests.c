#include <stdio.h>
#include <stdlib.h>
#include "Reader.h"

void printStrings(char** strings) {
    if (strings == NULL) {
        printf("The array of strings is empty.\n");
        return;
    }

    int i = 0;
    while (strings[i] != NULL) {
        printf("%s\n", strings[i]);
        i++;
    }
}

int main() {
    const char* filename = "FRANCE.MAP";

    char** strings = readStringsFromFile(filename);
    if (strings == NULL) {
        printf("Failed to read strings from file.\n");
        return 1;
    }

    printf("Strings in the file:\n");
    printStrings(strings);

    // Free allocated memory
    int i = 0;
    while (strings[i] != NULL) {
        free(strings[i]);
        i++;
    }
    free(strings);

    return 0;
}
