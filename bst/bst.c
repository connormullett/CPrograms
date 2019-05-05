
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


// bst functions
bst* create(){
    bst* b = (bst*)malloc(sizeof(bst));
    b->root = NULL;
    return b;
}

bst* insert(bst* tree, int data){
    Node* n = newNode(data);

    if(!tree->root){
        tree->root = n;
    } else {
        insertNode(n, tree->root);
    }

    return tree;
}

// returns -1 if searched term is 0
// else returns 0 if no found term
Node* search(bst* tree, int term){
    Node* node = searchNode(tree->root, term);
    if(node == NULL){
        return NULL;
    } else {
        return node;
    }
}

void print(bst* tree){
    // if node is empty
    if(tree->root == NULL) return;
    printNode(tree->root);
    printf("\n");
    return;
}

// node functions
Node* searchNode(Node* node, int term){
    if(node == NULL){
        // return null if not found
        return NULL;
    }

    if(node->data == term){
        return node;
    }

    if(term < node->data) {
        return searchNode(node->left, term);
    } else {
        return searchNode(node->right, term);
    }
}

Node* insertNode(Node* node, Node* root){
    if(node->data < root->data){
        if(root->left){
            printf("going left\n");
            return insertNode(node, root->left);
        } else {
            printf("insert left\n");
            root->left = node;
        }
    } else {
        if(root->right){
            printf("going right\n");
            return insertNode(node, root->right);
        } else {
            printf("insert right\n");
            root->right = node;
        }
    }
}

Node* newNode(int data){
    Node* rn = (Node*)malloc(sizeof(Node));
    rn->data = data;
    rn->left = NULL;
    rn->right = NULL;
    return rn;
}

void printNode(Node* node){
    if(node->left) printNode(node->left);

    if(node->right) printNode(node->right);

    printf("%d", node->data);
}

