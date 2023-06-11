#include <stdio.h>
#include "set.h"

int main() {
    Set set;
    initializeSet(&set);

    addElement(&set, 5);
    addElement(&set, 10);
    addElement(&set, 15);

    removeElement(&set, 10);

    printf("Set contains 5: %s\n", containsElement(&set, 5) ? "true" : "false");
    printf("Set contains 10: %s\n", containsElement(&set, 10) ? "true" : "false");

    return 0;
}
