
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// node declaration in bst.h
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


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

void print(bst* tree){
    printNode(tree->root);
    printf("\n");
    return;
}

// node functions
Node* insertNode(Node* node, Node* root){
    if(node->data < root->data){
        if(root->left){
            return insertNode(node, root->left);
        } else {
            root->left = node;
        }
    } else {
        if(root->right){
            return insertNode(node, root->right);
        } else {
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

