#ifndef ARN_H
#define ARN_H

typedef struct node
{
    int key;
    char color;
    struct node *left;
    struct node *rigth;
    struct node *father;
}Node;

Node *searchNode(Node *pointerRoot, int key);
Node *createNode(int key);
void inOrdem(Node *pointerRoot);
Node *external();
void moveFather(Node *pointerU, Node *pointerV, Node **pointernode, Node *external);
void rotationL(Node *pointerZ, Node **pointerRoot, Node *external);
void rotationR(Node *pointerZ, Node **pointerRoot, Node *external);
void routeRN(Node *pointerZ, Node **pointerRoot, Node *external);
void insertRN(Node *pointerZ, Node **pointerRoot, Node *external);
Node *successor(Node *pointerZ);
void removeRN(Node *pointerZ, Node **pointerRoot, Node *external);
int countNodes(Node *pointerRoot, int *count);


#endif