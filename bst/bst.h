
#ifndef BST_H
#define BST_H

struct Node {
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

typedef struct {
    Node*  root;
    int size;
} bst;

// bst functions
bst* create();
bst* insert(bst* tree, int data);
Node* search(bst* tree, int term);
int pop(bst* tree, int term);
void print(bst* tree);

// node functions
// TODO: implement parent in Node
Node* newNode(int data);
Node* insertNode(Node* node, Node* root);
Node* searchNode(Node* node, int term);
void printNode(Node* nodk);
Node* getParent(Node* root, Node* node);
#endif

