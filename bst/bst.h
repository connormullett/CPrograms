
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
bst* pop(bst* tree, int term);
void print(bst* tree);

// node functions
Node* deleteNode(Node* node, int term);
Node* minValueNode(Node* node);
Node* newNode(int data);
Node* insertNode(Node* node, Node* root);
Node* searchNode(Node* node, int term);
void printNode(Node* nodk);
Node* getParent(Node* root, Node* node);
#endif

