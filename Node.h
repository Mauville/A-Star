#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node {
    int id;
    int heuristic;
    Node** neighbors;
    int num_neighbors;
    int* edge_costs;
    int* g_score;
    Node* parent;
};

#endif /* NODE_H */
