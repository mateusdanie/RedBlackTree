#include <stdio.h>
#include <stdlib.h>
#include "ARN.h"

int main()
{
    
    return 0;
}

void moveFather(Node *pointerU, Node *pointerV, Node **pointerRoot){
    if(pointerU->father == NULL){
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

void rotationL(Node *pointerZ){

}

void rotationR(Node *pointerZ){

}

void routeRN(Node *pointerZ, Node **pointerRoot){
    while(pointerZ->father->color == 'R'){
        if(pointerZ->father == pointerZ->father->father->left){
            Node *pointerY;
            pointerY = pointerZ->father->father->rigth;

            if(pointerY->color == 'R'){
                pointerZ->father->color = pointerY->color = 'N';
                pointerZ->father->father->color = 'R';
                pointerZ = pointerZ->father->father;
            }else{
                if(pointerZ == pointerZ->father->rigth){
                    pointerZ = pointerZ->father;
                    rotationL(pointerZ);
                }

                pointerZ->father->color = 'N';
                pointerZ->father->father->color = 'R';
                rotationD(pointerZ->father->father);
            }

        }else{

        } 
    }

    (*pointerRoot)->color = 'N';
}

void insertRN(Node *pointerZ, Node **pointerRoot){
   
    Node *pointerY = NULL;//Externo
     Node *pointer = (*pointerRoot);

    while(pointer != pointerY){
        pointerY = pointer;

        if(pointerZ->key == pointer->key){
            printf("Chave já existe!!!\n");
            pointerY = NULL;
            pointer = pointerY;
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

        if(pointerY == NULL){//Externo
            (*pointerRoot) = pointerZ;
        }else{
            if(pointerZ->key < pointerY->key){
                pointerY->left = pointerZ;
            }else{
                pointerY->rigth = pointerZ;
            }
        }

        pointerZ->left = pointerZ->rigth = NULL;//Externo
        pointerZ->color = 'R';
        routeRN(pointerZ, pointerRoot);
    }
}
