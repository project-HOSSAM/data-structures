#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node *createBinarySearchTree(int initialData);

struct Node *insertToBinarySearchTree(struct Node *root, int data);

void *searchBinarySearchTree(struct Node *root, int data);

bool deleteFromBinarySearchTree(struct Node *root, int data);

struct Node *maxNode(struct Node *root);
struct Node *minNode(struct Node *root);
