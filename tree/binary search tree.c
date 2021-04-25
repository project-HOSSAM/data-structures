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
  // node has 2 children
  struct Node *replacmentNode = minNode(nodeToDelete->right);
  if (replacmentNode->parent->data > replacmentNode->data) {
    replacmentNode->parent->left = NULL;
  } else {
    replacmentNode->parent->right = NULL;
  }
  replacmentNode->parent = nodeToDelete->parent;
  nodeToDelete->left->parent = replacmentNode;
  nodeToDelete->right->parent = replacmentNode;
  replacmentNode->left = nodeToDelete->left;
  replacmentNode->right = nodeToDelete->right;
  if (nodeToDelete->data > nodeToDelete->parent->data) {
    nodeToDelete->parent->right = replacmentNode;
  } else {
    nodeToDelete->parent->left = replacmentNode;
  };
  free(nodeToDelete);
  return true;
}

void preOrder(struct Node *root, void (*callback)(int)) {
  if (root == NULL)
    return;
  callback(root->data);
  preOrder(root->left, callback);
  preOrder(root->right, callback);
};

void inOrder(struct Node *root, void (*callback)(int)) {
  if (root == NULL)
    return;
  inOrder(root->left, callback);
  callback(root->data);
  inOrder(root->right, callback);
}

void postOrder(struct Node *root, void (*callback)(int)) {
  if (root == NULL)
    return;
  postOrder(root->left, callback);
  postOrder(root->right, callback);
  callback(root->data);
}
