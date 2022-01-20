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


void moveFather(Node *pointerU, Node *pointerV, Node **pointernode);
void rotationL(Node *pointerZ);
void rotationR(Node *pointerZ);
void routeRN(Node *pointerZ,  Node **pointerRoot);
void insertRN(Node *pointerZ, Node **pointerRoot);


#endif