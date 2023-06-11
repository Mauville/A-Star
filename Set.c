#include <stdio.h>
#include "set.h"

void initializeSet(Set *set) {
    set->size = 0;
}

void addElement(Set *set, int element) {
    if (set->size == MAX_SIZE) {
        printf("Set is full. Cannot add more elements.\n");
        return;
    }

    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            printf("Element already exists in the set.\n");
            return;
        }
    }

    set->elements[set->size++] = element;
    printf("Element %d added to the set.\n", element);
}

void removeElement(Set *set, int element) {
    int index = -1;

    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element not found in the set.\n");
        return;
    }

    for (int i = index; i < set->size - 1; i++) {
        set->elements[i] = set->elements[i + 1];
    }

    set->size--;
    printf("Element %d removed from the set.\n", element);
}

int containsElement(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1;
        }
    }

    return 0;
}
