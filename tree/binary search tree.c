#include "./binary search tree.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *createBinarySearchTree(int initialData) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = initialData;
  return newNode;
};

struct Node *maxNode(struct Node *root) {
  while (root->right) {
    root = root->right;
  };
  return root;
}

struct Node *minNode(struct Node *root) {
  while (root->left) {
    root = root->left;
  };
  return root;
}

struct Node *insertToBinarySearchTree(struct Node *root, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;
  while (1) {
    if (root->data > data) {
      // go left
      if (!root->left) {
        root->left = newNode;
        newNode->parent = root;
        return newNode;
      }
      root = root->left;
    } else {
      // go right
      if (!root->right) {
        root->right = newNode;
        newNode->parent = root;
        return newNode;
      }
      root = root->right;
    }
  }
}

void *searchBinarySearchTree(struct Node *root, int data) {
  while (root) {
    if (root->data == data)
      return root;
    if (root->data > data) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return NULL;
}

bool deleteFromBinarySearchTree(struct Node *root, int data) {
  struct Node *nodeToDelete = searchBinarySearchTree(root, data);
  if (nodeToDelete == NULL)
    return false;
  if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
    // if node has no children
    free(nodeToDelete);
    return true;
  } else if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) {
    // if node have 1 child
    struct Node *parent = nodeToDelete->parent;
    struct Node *child;
    if (nodeToDelete->left == NULL) {
      child = nodeToDelete->right;
    } else {
      child = nodeToDelete->left;
    }
    child->parent = parent;
    if (nodeToDelete->data < parent->data) {
      parent->left = child;
      return true;
    };
    parent->right = child;
    return true;
  };
  // node has 3 children
  struct Node *replacmentNode = minNode(nodeToDelete->right);
  replacmentNode->parent->left = NULL;
  replacmentNode->parent = nodeToDelete->parent;
  nodeToDelete->left->parent = replacmentNode;
  nodeToDelete->right->parent = replacmentNode;
  if (nodeToDelete->data > nodeToDelete->parent->data) {
    nodeToDelete->parent->right = replacmentNode;
  } else {
    nodeToDelete->parent->left = replacmentNode;
  };
  free(nodeToDelete);
  return true;
}

int main() {
  struct Node *node = createBinarySearchTree(50);
  insertToBinarySearchTree(node, 30);
  insertToBinarySearchTree(node, 70);
  insertToBinarySearchTree(node, 20);
  insertToBinarySearchTree(node, 40);
  insertToBinarySearchTree(node, 60);
  insertToBinarySearchTree(node, 80);
  insertToBinarySearchTree(node, 35);
  insertToBinarySearchTree(node, 65);
  insertToBinarySearchTree(node, 75);
  insertToBinarySearchTree(node, 77);
  insertToBinarySearchTree(node, 85);
  bool r = deleteFromBinarySearchTree(node, 70);
  if (r) {
    printf("deletion went ok");
    return 0;
  }
  printf("deletion went wrong\n");
  printf("the new root is %d", node->data);
}
