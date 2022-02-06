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

Node *external();
void moveFather(Node *pointerU, Node *pointerV, Node **pointernode);
void rotationL(Node *pointerZ, Node **pointerRoot, Node *external);
void rotationR(Node *pointerZ, Node **pointerRoot, Node *external);
void routeRN(Node *pointerZ, Node **pointerRoot, Node *external);
void insertRN(Node *pointerZ, Node **pointerRoot, Node *external);
Node *successor(Node *pointerZ);
void removeRN(Node *pointerZ, Node **pointerRoot, Node *external);


#endif