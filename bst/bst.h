
#ifndef BST_H
#define BST_H

// definition in bst.c
typedef struct Node Node;

typedef struct {
    Node*  root;
} bst;

// bst functions
bst* create();
bst* insert(bst* tree, int data);
void print(bst* tree);

// node functions
Node* newNode(int data);
Node* insertNode(Node* node, Node* root);
void printNode(Node* nodk);

#endif

