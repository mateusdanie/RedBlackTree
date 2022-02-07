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

Node *searchNode(Node *pointerRoot, int key){
    if(pointerRoot->key == key){
        Node *new = (Node*) malloc(sizeof(Node));
        new->key = pointerRoot->key;
        new->left = pointerRoot->left;
        new->rigth = pointerRoot->rigth;
        new->father = pointerRoot->father;
        return new;
    }

    if(pointerRoot->left != NULL){
        searchNode(pointerRoot->left, key);
    }

    if(pointerRoot->rigth != NULL){
        searchNode(pointerRoot->rigth, key);
    }
}

Node *external(){
    Node *externalNode = (Node*) malloc(sizeof(Node));
    externalNode->key = 0;
    externalNode->color = 'N';
    externalNode->left = NULL;
    externalNode->rigth = NULL;
    externalNode->father = NULL;

    return externalNode;
}

void preOrdem(Node *pointerRoot){
    if(pointerRoot->key != 0){
        printf("Key = %d ", pointerRoot->key);
    }else{
        printf("External ");
    }

    if(pointerRoot->left != NULL){
        preOrdem(pointerRoot->left);
    }

    if(pointerRoot->rigth != NULL){
        preOrdem(pointerRoot->rigth);
    }

}

Node *createNode(int key){
    Node *new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->color = 'N';
    new->left = NULL;
    new->rigth = NULL;
    new->father = NULL;

    return new;
}

void moveFather(Node *pointerU, Node *pointerV, Node **pointerRoot, Node *external){
    if(pointerU->father == external){
        (*pointerRoot) = pointerV;
    }else{
        if(pointerU == pointerU->father->left){
            pointerU->father->left = pointerV;
        }else{
            pointerU->father->rigth = pointerV;
        }
    }

    pointerV->father = pointerU->father;
}

void rotationL(Node *pointerZ, Node **pointerRoot, Node *external){
    Node *pointerY;
    pointerY = pointerZ->rigth;

    if(pointerZ->rigth != external){
        pointerZ->rigth->father = pointerZ;
    }

    pointerY->father = pointerZ->father;

    if(pointerZ->father == external){
        (*pointerRoot) = pointerY;
    }else if(pointerZ == pointerZ->father->left){
        pointerZ->father->left = pointerY;
    }else{
        pointerZ->father->rigth = pointerY;
    }

    pointerY->left = pointerZ;
    pointerZ->father = pointerY;
}

void rotationR(Node *pointerZ, Node **pointerRoot, Node *external){
    Node *pointerY;
    pointerY = pointerZ->left;
    
    if(pointerZ->left != external){
        pointerZ->left->father = pointerZ;
    }

    pointerY->father = pointerZ->father;

    if(pointerZ->father == external){
        (*pointerRoot) = pointerY;
    }else if(pointerZ == pointerZ->father->left){
        pointerZ->father->left = pointerY;
    }else{
        pointerZ->father->rigth = pointerY;
    }

    pointerY->rigth = pointerZ;
    pointerZ->father = pointerY;
}

void routeRN(Node *pointerZ, Node **pointerRoot, Node *external){
    while(pointerZ->father->color == 'R'){
        if(pointerZ->father == pointerZ->father->father->left){
            Node *pointerY;
            pointerY = pointerZ->father->father->rigth;

            if(pointerY->color == 'R'){
                pointerY->color = 'N';
                pointerZ->father->color = 'N';
                pointerZ->father->father->color = 'R';
                pointerZ = pointerZ->father->father;
            }else{
                if(pointerZ == pointerZ->father->rigth){
                    pointerZ = pointerZ->father;
                    rotationL(pointerZ, pointerRoot, external);
                }

                pointerZ->father->color = 'N';
                pointerZ->father->father->color = 'R';
                rotationR(pointerZ->father->father, pointerRoot, external);
            }

        }else{
           Node *pointerY;
           pointerY = pointerZ->father->father->left;
           if(pointerY->color == 'R'){
                pointerY->color = 'N';
                pointerZ->father->color = 'N';
                pointerZ->father->father->color = 'R';
                pointerZ = pointerZ->father->father; 
           }else{
                if(pointerZ == pointerZ->father->left){
                    pointerZ = pointerZ->father;
                    rotationR(pointerZ, pointerRoot, external);
                }

                pointerZ->father->color = 'N';
                pointerZ->father->father->color = 'R';
                rotationL(pointerZ->father->father, pointerRoot, external);
           }
        } 
    }

    (*pointerRoot)->color = 'N';
}

void insertRN(Node *pointerZ, Node **pointerRoot, Node *external){
   
    Node *pointerY;
    pointerY = external;
    Node *pointer;
    pointer = (*pointerRoot);

    while(pointer != external){
        pointerY = pointer;

        if(pointerZ->key == pointer->key){
            printf("Chave já existe!!!\n");
            pointerY = NULL;
            pointer = external;
        }else{
            if(pointerZ->key < pointer->key){
                pointer = pointer->left;
            }else{
                pointer = pointer->rigth;
            }
        }
    }

    if(pointerY != NULL){
        pointerZ->father = pointerY;

        if(pointerY == external){
            (*pointerRoot) = pointerZ;
        }else{
            if(pointerZ->key < pointerY->key){
                pointerY->left = pointerZ;
            }else{
                pointerY->rigth = pointerZ;
            }
        }

        pointerZ->left = external;
        pointerZ->rigth = external;
        pointerZ->color = 'R';
        routeRN(pointerZ, pointerRoot, external);
    }
}

Node *successor(Node *pointerZ){
    return pointerZ->father;
}

removeRouteRN(Node *pointerX, Node **pointerRoot, Node *external){
    while(pointerX != (*pointerRoot) && pointerX->color != 'R'){
        if(pointerX == pointerX->father->left){
            Node *pointerW;

            pointerW = pointerX->father->rigth;

            if(pointerW->color == 'R'){
                pointerX->father->color = 'R';
                pointerW->color = 'N';
                rotationL(pointerX->father, pointerRoot, external);
                pointerW = pointerX->father->rigth;
            }

            if(pointerW->rigth->color == 'N' && pointerW->left->color == 'N'){
                pointerW->color = 'R';
                pointerX = pointerX->father;
            }else{
                if(pointerW->left->color == 'R'){
                    pointerW->left->color = 'N';
                    pointerW->color = 'R';
                    rotationR(pointerW, pointerRoot, external);
                    pointerW = pointerX->father->rigth;
                }

                pointerW->color = pointerX->father->color;
                pointerW->rigth->color = 'N';
                rotationL(pointerX->father, pointerRoot, external);
                pointerX = *(pointerRoot);
            }
        }else{
            Node *pointerW;

            pointerW = pointerX->father->left;

            if(pointerW->color == 'R'){
                pointerX->father->color = 'R';
                pointerW->color = 'N';
                rotationL(pointerX->father, pointerRoot, external);
                pointerW = pointerX->father->left;
            }

            if(pointerW->rigth->color == 'N' && pointerW->left->color == 'N'){
                pointerW->color = 'R';
                pointerX = pointerX->father;
            }else{
                if(pointerW->rigth->color == 'R'){
                    pointerW->rigth->color = 'N';
                    pointerW->color = 'R';
                    rotationR(pointerW, pointerRoot, external);
                    pointerW = pointerX->father->left;
                }

                pointerW->color = pointerX->father->color;
                pointerW->left->color = 'N';
                rotationL(pointerX->father, pointerRoot, external);
                pointerX = *(pointerRoot);
            }
        }

    }
}

void removeRN(Node *pointerZ, Node **pointerRoot, Node *external){
    char originalColor;
    Node *pointerY, *pointerX;
    pointerY = pointerZ; originalColor = pointerY->color;

    if (pointerY->left == external){

        pointerX = pointerZ->rigth;
        moveFather(pointerZ, pointerZ->rigth, pointerRoot, external);
    }else{
        if (pointerY->rigth == external) {

            pointerX = pointerZ->left;
            moveFather(pointerZ, pointerZ->left, pointerRoot, external);
        }else{
            pointerY = successor(pointerX); originalColor = pointerY->color;
            pointerX = pointerY->rigth;

            if(pointerY->father != pointerZ){
                moveFather(pointerY, pointerX, pointerRoot, external);
                pointerY->rigth = pointerZ->rigth;
                pointerY->father->rigth = pointerY;
            }

            moveFather(pointerZ, pointerY, pointerRoot, external);
            pointerY->left = pointerZ->left;
            pointerY->left->father = pointerY;
        }
    }

    if(originalColor == 'N'){
        removeRouteRN(pointerX, pointerRoot, external);
    }
}

void checkRN(Node *pointerRoot, int *he, int *hd){

    if(pointerRoot->left != NULL){
        if(pointerRoot->color == 'N' && pointerRoot->key != 0){
            (*he)++;
        } 
        checkRN(pointerRoot->left, he, hd);
    }

    if(pointerRoot->rigth != NULL){
        if(pointerRoot->color == 'N' && pointerRoot->key != 0){
            (*hd)++;
        } 
        checkRN(pointerRoot->rigth, he, hd);
    }

}

void countNodes(Node *pointerRoot, int *count, Node *externalNode){

    (*count)++;

    if(pointerRoot->left != externalNode){
        countNodes(pointerRoot->left, count, externalNode);
    }

    if(pointerRoot->rigth != externalNode){
        countNodes(pointerRoot->rigth, count, externalNode);
    }
}

void freeRN(Node *pointerRoot){
    if(pointerRoot->left != NULL){
        freeRN(pointerRoot->left);
    }

    if(pointerRoot->rigth != NULL){
        freeRN(pointerRoot->rigth);
    } 

    free(pointerRoot);
}

#endif