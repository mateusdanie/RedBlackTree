#ifndef ARN_H
#define ARN_H

typedef struct no
{
    int key;
    char color;
    struct no *left;
    struct no *rigth;
    struct no *father;
}No;


void moveFather(No *pointerU, No *pointerV, No **pointerRoot);
void insertRN();

#endif