#ifndef ARN_H
#define ARN_H

typedef struct node{
	int key;
	char color;
	struct node *left;
    struct node *rigth;
    struct node *father;
} Node;

typedef struct tree{
	struct node *root, *external;
} RNTree;

RNTree createTree() {
	RNTree tree;

	tree.external = malloc(sizeof(Node));
	tree.external->key = 0;
	tree.external->color = 'N';
	tree.root = tree.external;

	return tree;
}

void rotationL(RNTree *tree, Node *pointerX) {
	Node *pointerY = pointerX->rigth;
	pointerX->rigth = pointerY->left;

	if(pointerY->left != tree->external){
		pointerY->left->father = pointerX;
	}

	pointerY->father = pointerX->father;

	if(pointerX->father == tree->external){
		tree->root = pointerY;
	}else if(pointerX == pointerX->father->left){
		pointerX->father->left = pointerY;
	}else{
		pointerX->father->rigth = pointerY;
	}

	pointerY->left = pointerX;
	pointerX->father = pointerY;
}

void rotationR(RNTree *tree, Node *pointerY) {
	Node *pointerX = pointerY->left;
	pointerY->left = pointerX->rigth;

	if(pointerX->rigth != tree->external){
		pointerX->rigth->father = pointerY;
	}

	pointerX->father = pointerY->father;

	if(pointerX->father == tree->external){
		tree->root = pointerX;
	}else if(pointerY == pointerY->father->left){
		pointerY->father->left = pointerX;
	}else{
		pointerY->father->rigth = pointerX;
	}

	pointerX->rigth = pointerY;
	pointerY->father = pointerX;
}

void routeRN(RNTree *tree, Node *pointerZ) {
	while(pointerZ->father->color == 'R') {
		if(pointerZ->father == pointerZ->father->father->left) {
			Node *pointerY = pointerZ->father->father->rigth;

			if(pointerY->color == 'R') {
				pointerZ->father->color = 'N';
				pointerY->color = 'N';
				pointerZ->father->father->color = 'R';
				pointerZ = pointerZ->father->father;
			} else {
				if(pointerZ == pointerZ->father->rigth) {
					pointerZ = pointerZ->father;
					rotationL(tree, pointerZ);
				}

				pointerZ->father->color = 'N';
				pointerZ->father->father->color = 'R';
				rotationR(tree, pointerZ->father->father);
			}
		} else {
			Node *pointerY = pointerZ->father->father->left;

			if(pointerY->color == 'R') {
				pointerZ->father->color = 'N';
				pointerY->color = 'N';
				pointerZ->father->father->color = 'R';
				pointerZ = pointerZ->father->father;
			} else {
				if(pointerZ == pointerZ->father->left) {
					pointerZ = pointerZ->father;
					rotationR(tree, pointerZ);
				}

				pointerZ->father->color = 'N';
				pointerZ->father->father->color = 'R';
				rotationL(tree, pointerZ->father->father);
			}
		}
	}

	tree->root->color = 'N';
}

void insertRN(RNTree *tree, int key) {
	Node *pointerX = tree->root, *pointerY = tree->external;

	while(pointerX != tree->external) {
		pointerY = pointerX;

		if(key < pointerX->key){
			pointerX = pointerX->left;
		}else{
			pointerX = pointerX->rigth;
		}
	}

	Node *pointerZ = malloc(sizeof(Node));
	pointerZ->key = key;
	pointerZ->color = 'R';
	pointerZ->father = pointerY;
	pointerZ->left = tree->external;
	pointerZ->rigth = tree->external;

	if(pointerY == tree->external){
		tree->root = pointerZ;
	}else if(key < pointerY->key){
		pointerY->left = pointerZ;
	}else{
		pointerY->rigth = pointerZ;
	}

	routeRN(tree, pointerZ);
}

Node *searchNode(Node *aux, Node *external, int key) {
	if(aux == external){
		return external;
	}else if(aux->key > key){
		return searchNode(aux->left, external, key);
	}else if(aux->key < key){
		return searchNode(aux->rigth, external, key);
	}else{
		return aux;
	}
}

void moveFather(RNTree *tree, Node *pointerX, Node *pointerY) {
	if(pointerX->father == tree->external){
		tree->root = pointerY;
	}else if(pointerX == pointerX->father->left){
		pointerX->father->left = pointerY;
	}else{
		pointerX->father->rigth = pointerY;
	}

	pointerY->father = pointerX->father;
}

Node *successor(RNTree *tree, Node *aux) {
	while(aux->left != tree->external){
		aux = aux->left;
	}

	return aux;
}

void removeRouteRN(RNTree *tree, Node *pointerX) {
	while(pointerX != tree->root && pointerX->color == 'N') {
		if(pointerX == pointerX->father->left) {
			Node *pointerW = pointerX->father->rigth;

			if(pointerW->color == 'R') {
				pointerW->color = 'N';
				pointerX->father->color = 'R';
				rotationL(tree, pointerX->father);
				pointerW = pointerX->father->rigth;
			}

			if(pointerW->left->color == 'N' && pointerW->rigth->color == 'N') {
				pointerW->color = 'R';
				pointerX = pointerX->father;
			} else {
				if(pointerW->rigth->color == 'N') {
					pointerW->left->color = 'N';
					pointerW->color = 'R';
					rotationR(tree, pointerW);
					pointerW = pointerX->father->rigth;
				}

				pointerW->color = pointerX->father->color;
				pointerX->father->color = 'N';
				pointerW->rigth->color = 'N';
				rotationL(tree, pointerX->father);
				pointerX = tree->root;
			}
		} else {
			Node *pointerW = pointerX->father->left;

			if(pointerW->color == 'R') {
				pointerW->color = 'N';
				pointerX->father->color = 'R';
				rotationR(tree, pointerX->father);
				pointerW = pointerX->father->left;
			}

			if(pointerW->rigth->color == 'N' && pointerW->left->color == 'N') {
				pointerW->color = 'R';
				pointerX = pointerX->father;
			} else {
				if(pointerW->left->color == 'N') {
					pointerW->rigth->color = 'N';
					pointerW->color = 'R';
					rotationL(tree, pointerW);
					pointerW = pointerX->father->left;
				}

				pointerW->color = pointerX->father->color;
				pointerX->father->color = 'N';
				pointerW->left->color = 'N';
				rotationR(tree, pointerX->father);
				pointerX = tree->root;
			}
		}
	}

	pointerX->color = 'N';
}

void removeRN(RNTree *tree, int key) {
	Node *pointerZ = searchNode(tree->root, tree->external, key);

	if(pointerZ == tree->external){
		return;
	}

	Node *pointerY = pointerZ, *pointerX;
	char originalColor = pointerY->color;

	if(pointerZ->left == tree->external) {
		pointerX = pointerZ->rigth;
		moveFather(tree, pointerZ, pointerZ->rigth);
	} else if(pointerZ->rigth == tree->external) {
		pointerX = pointerZ->left;
		moveFather(tree, pointerZ, pointerZ->left);
	} else {
		pointerY = successor(tree, pointerZ->rigth);
		originalColor = pointerY->color;
		pointerX = pointerY->rigth;

		if(pointerY->father == pointerZ)
			pointerX->father = pointerY;
		else {
			moveFather(tree, pointerY, pointerY->rigth);
			pointerY->rigth = pointerZ->rigth;
			pointerY->rigth->father = pointerY;
		}

		moveFather(tree, pointerZ, pointerY);
		pointerY->left = pointerZ->left;
		pointerY->left->father = pointerY;
		pointerY->color = pointerZ->color;
	}

	if(originalColor == 'N')
		removeRouteRN(tree, pointerX);

	free(pointerZ);
}


int height(Node *pointer, RNTree tree){
    int he, hd;

    if(pointer == tree.external){
        return 0;
    }else{
        he = height(pointer->left, tree);
        hd = height(pointer->rigth, tree);
    }

    if(pointer->left->color == 'N'){
		if(pointer != tree.root){
			return he + 1;
		}
    }else if(pointer->rigth->color == 'N'){
        if(pointer != tree.root){
			return hd + 1;
		}
    }
    
}

int checkRN(Node *pointer, int *he, int *hd, RNTree tree){
   if(pointer->left != tree.external){
       checkRN(pointer->left, he, hd, tree);
    }

    if(pointer->rigth != tree.external){
        checkRN(pointer->rigth, he, hd,tree);
    }

    (*he) = height(pointer->left, tree);
    (*hd) = height(pointer->rigth, tree);

}

int countNodes(Node *pointer, int *count, Node *external){
    if(pointer->left != external){
        (*count)++;
        countNodes(pointer->left, count, external);
    }

    if(pointer->rigth != external){
        (*count)++;
        countNodes(pointer->rigth, count, external);
    }
}

void freeRN(Node *pointer, Node *external){
    if(pointer->left != external){
        freeRN(pointer->left, external);
    }

    if(pointer->rigth != external){
        freeRN(pointer->rigth, external);
    } 

    free(pointer);
}



#endif
