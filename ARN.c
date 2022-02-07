#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ARN.h"

void arrayCreate(int *array, int amount);

int main()
{
    srand(time(NULL));
    Node *externalNode = external();
    Node *Root = externalNode;
    int *arrayADD = malloc(sizeof(Node) * 10000);

    arrayCreate(arrayADD, 10000);

   for (int i = 0; i < 1000; i++)
   {
        int count = 0, he = 0, hd = 0;
        
        for(int j = 0; j <  10000; j++)
        {
            insertRN(createNode(arrayADD[j]), &Root, externalNode);
        }

        countNodes(Root, &count, externalNode);

        printf("Nos: %d\n", count);

        checkRN(Root, &he, &hd);

        if(he == hd){
            printf("Eh rubro negra!!!\n");
        }else{
            printf("Nao eh rubro negra!!!\n");
        }

        for(int j = 0; j < 1000; j++)
        {
            removeRN(searchNode(Root,arrayADD[j], externalNode), &Root, externalNode);
        }

        count = 0;

        countNodes(Root, &count, externalNode);

        printf("Nos: %d\n", count);

        he = 0; hd = 0;

        checkRN(Root, &he, &hd);
            
        if(he == hd){
            printf("Eh rubro negra!!!\n");
        }else{
            printf("Nao eh rubro negra!!!\n");
        }
            
        freeRN(Root, externalNode);

   }
   
    return 0;
}

void arrayCreate(int *array, int amount){
    int flag;
    for(int i = 0; i < amount; i++) {
        array[i] = rand() % 100000;
        flag = 0;
        for (int j = 0; j < i && flag == 0; j++) {
            if (array[i] == array[j])
                flag = 1;
        }
        if (flag == 1)
            i--;
    }
}

