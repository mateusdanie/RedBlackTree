#include <stdio.h>
#include <stdlib.h>
#include "ARN.h"

int main()
{
    
    return 0;
}

void moveFather(No *pointerU, No *pointerV, No **pointerRoot){
    if(pointerU->father == NULL){
        (*pointerRoot) = pointerV;
    }else{
        if(pointerU == pointerU->father->left){
            pointerU->father->left = pointerV;
        }else{
            pointerU->father->rigth = pointerV;
        }
    }

    pointerV->father = pointerU->father
}