#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ARN.h"
#include <stdbool.h>

void arrayCreate(int *array, int amount);

int main()
{
    RNTree tree = createTree();
    srand(time(NULL));

    int *arrayADD = malloc(sizeof(Node) * 10000);
    arrayCreate(arrayADD, 10000);


    for(int i = 0; i < 1; i++)
    {
        
        int count = 1, he = 0, hd = 0;
        

        for(int j = 0; j < 10000; j++)
        {
            insertRN(&tree, arrayADD[j]);
        }

        countNodes(tree.root, &count, tree.external);
        printf("Nos: %d\n", count);

        checkRN(tree.root, &he, &hd, tree);

        if(he == hd){
            printf("Eh rubro negra\n");
        }else{
            printf("Nao eh rubro negra\n");
        }

        for(int j = 0; j < 1000; j++)
        {
            removeRN(&tree, arrayADD[j]);
        }

        count = 1, he = 0, hd = 0;

        countNodes(tree.root, &count, tree.external);
        printf("Nos: %d\n", count);

        checkRN(tree.root, &he, &hd, tree);

        if(he == hd){
            printf("Eh rubro negra\n");
        }else{
            printf("Nao eh rubro negra\n");
        }

        freeRN(tree.root, tree.external);
    }

	int *arrayADD = malloc(sizeof(Node) * 100);
    arrayCreate(arrayADD, 100);

	 int count = 1, he = 0, hd = 0;
        

        for(int j = 0; j < 100; j++)
        {
            insertRN(&tree, arrayADD[j]);
        }

        countNodes(tree.root, &count, tree.external);
        printf("Nos: %d\n", count);

        for(int j = 0; j < 10; j++)
        {
            removeRN(&tree, arrayADD[j]);
        }

        count = 1, he = 0, hd = 0;

        countNodes(tree.root, &count, tree.external);
        printf("Nos: %d\n", count);

        freeRN(tree.root, tree.external);
    

    return 0;
}

void arrayCreate(int *array, int amount){
    int flag;
    for(int i = 0; i < amount; i++) {
        array[i] = (rand() % 100000) + 1;
        flag = 0;
        for (int j = 0; j < i && flag == 0; j++) {
            if (array[i] == array[j])
                flag = 1;
        }
        if (flag == 1)
            i--;
    }
}

