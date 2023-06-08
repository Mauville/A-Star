#include "PriorityQueue.h"
#include <stdlib.h>

void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
    pq->capacity = 10;
    pq->data = (Node**)malloc(pq->capacity * sizeof(Node*));
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void resizePriorityQueue(PriorityQueue* pq) {
    pq->capacity *= 2;
    pq->data = (Node**)realloc(pq->data, pq->capacity * sizeof(Node*));
}

void enqueue(PriorityQueue* pq, Node* node) {
    if (pq->size == pq->capacity)
        resizePriorityQueue(pq);

    pq->data[pq->size] = node;
    int currentIndex = pq->size;
    int parentIndex = (currentIndex - 1) / 2;

    while (currentIndex > 0 && pq->data[currentIndex]->heuristic < pq->data[parentIndex]->heuristic) {
        swap(&pq->data[currentIndex], &pq->data[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }

    pq->size++;
}

Node* dequeueMin(PriorityQueue* pq) {
    if (pq->size == 0)
        return NULL;

    Node* minNode = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    int currentIndex = 0;

    while (1) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int smallestChildIndex = currentIndex;

        if (leftChildIndex < pq->size && pq->data[leftChildIndex]->heuristic < pq->data[smallestChildIndex]->heuristic)
            smallestChildIndex = leftChildIndex;

        if (rightChildIndex < pq->size && pq->data[rightChildIndex]->heuristic < pq->data[smallestChildIndex]->heuristic)
            smallestChildIndex = rightChildIndex;

        if (smallestChildIndex != currentIndex) {
            swap(&pq->data[currentIndex], &pq->data[smallestChildIndex]);
            currentIndex = smallestChildIndex;
        } else {
            break;
        }
    }

    return minNode;
}

int isInPriorityQueue(PriorityQueue* pq, Node* node) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->data[i] == node)
            return 1;
    }
    return 0;
}
