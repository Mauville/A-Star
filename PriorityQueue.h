#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Node.h"

typedef struct {
    Node** data;
    int size;
    int capacity;
} PriorityQueue;

void initializePriorityQueue(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, Node* node);
Node* dequeueMin(PriorityQueue* pq);
int isInPriorityQueue(PriorityQueue* pq, Node* node);

#endif /* PRIORITY_QUEUE_H */
