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
    int *arrayADD = malloc(sizeof(Node) * 100);

    arrayCreate(arrayADD, 100);

    int count = 0, he = 0, hd = 0;
        
    for(int i = 0; i < 100; i++)
    {
        insertRN(createNode(arrayADD[i]), &Root, externalNode);
        printf("i = %d\n", i);
    }

    countNodes(Root, &count, externalNode);

    printf("Nos: %d\n", count);

        // checkRN(Root, &he, &hd);

        // if(he == hd){
        //     printf("Eh rubro negra!!!\n");
        // }else{
        //     printf("Nao eh rubro negra!!!\n");
        // }

        // for(int k = 0; k < 1000; k++)
        // {
        //     removeRN(searchNode(Root,arrayADD[k]), &Root, externalNode);
        // }

        // count = 0;

        // countNodes(Root, &count, externalNode);

        // printf("Nos: %d\n", count);

        // he = 0; hd = 0;

        // checkRN(Root, &he, &hd);
         
        // if(he == hd){
        //     printf("Eh rubro negra!!!\n");
        // }else{
        //     printf("Nao eh rubro negra!!!\n");
        // }
        
        // freeRN(Root);

        // printf("%d\n", i);

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

