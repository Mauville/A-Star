#ifndef SET_H
#define SET_H

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initializeSet(Set *set);
void addElement(Set *set, int element);
void removeElement(Set *set, int element);
int containsElement(Set *set, int element);

#endif /* SET_H */
