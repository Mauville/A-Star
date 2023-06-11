#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Helper function to create a new Node
Node* createNode(int heuristic) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->heuristic = heuristic;
    return newNode;
}

// Test case for initializePriorityQueue
void testInitializePriorityQueue() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    assert(pq.size == 0);
    assert(pq.capacity == 10);
    assert(pq.data != NULL);

    printf("initializePriorityQueue test passed.\n");
}

// Test case for enqueue
void testEnqueue() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    Node* node1 = createNode(5);
    enqueue(&pq, node1);

    Node* node2 = createNode(3);
    enqueue(&pq, node2);

    Node* node3 = createNode(7);
    enqueue(&pq, node3);

    Node* node4 = createNode(1);
    enqueue(&pq, node4);

    assert(pq.size == 4);
    assert(pq.data[0]->heuristic == 1);
    assert(pq.data[1]->heuristic == 3);
    assert(pq.data[2]->heuristic == 7);
    assert(pq.data[3]->heuristic == 5);

    printf("enqueue test passed.\n");
}

// Test case for dequeueMin
void testDequeueMin() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    Node* node1 = createNode(5);
    enqueue(&pq, node1);

    Node* node2 = createNode(3);
    enqueue(&pq, node2);

    Node* node3 = createNode(7);
    enqueue(&pq, node3);

    Node* node4 = createNode(1);
    enqueue(&pq, node4);

    Node* minNode = dequeueMin(&pq);

    assert(minNode->heuristic == 1);
    assert(pq.size == 3);
    assert(pq.data[0]->heuristic == 3);
    assert(pq.data[1]->heuristic == 5);
    assert(pq.data[2]->heuristic == 7);

    free(minNode);

    printf("dequeueMin test passed.\n");
}

// Test case for isInPriorityQueue
void testIsInPriorityQueue() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    Node* node1 = createNode(5);
    enqueue(&pq, node1);

    Node* node2 = createNode(3);
    enqueue(&pq, node2);

    Node* node3 = createNode(7);
    enqueue(&pq, node3);

    assert(isInPriorityQueue(&pq, node2) == 1);
    assert(isInPriorityQueue(&pq, node1) == 1);
    assert(isInPriorityQueue(&pq, node3) == 1);

    Node* newNode = createNode(10);
    assert(isInPriorityQueue(&pq, newNode) == 0);

    printf("isInPriorityQueue test passed.\n");
}

int runPriorityQueueTests() {
    testInitializePriorityQueue();
    testEnqueue();
    testDequeueMin();
    testIsInPriorityQueue();

    return 0;
}
