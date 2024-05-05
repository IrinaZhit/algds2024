#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int priority;
    struct Node *left, *right;
} Node;

Node* create(int key, int priority) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->priority = priority;
    node->left = node->right = NULL;
    return node;
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->priority < b->priority)
        return b->left = merge(a, b->left), b;
    return a->right = merge(a->right, b), a;
}

Node* insert(Node* root, int key, int priority) {
    if (!root) return create(key, priority);
    if (key <= root->key) {
        root->left = insert(root->left, key, priority);
        if (root->left && root->left->priority > root->priority)
            return root = root->left->right = rotateRight(root->left), root;
    } else {
        root->right = insert(root->right, key, priority);
        if (root->right && root->right->priority > root->priority)
            return root = root->right->left = rotateLeft(root->right), root;
    }
    return root;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* split(Node* root, int key, Node** left, Node** right) {
    if (!root) {
        *left = *right = NULL;
    } else if (key < root->key) {
        split(root->left, key, left, &root->left);
        *right = root;
    } else {
        split(root->right, key, &root->right, right);
        *left = root;
    }
    return root;
}
