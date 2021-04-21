#include <cstddef>
#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;
  Node *parent;
};

class BinarySearchTree {
private:
  Node *root;

public:
  Node *search(int data) {
    if (this->root == nullptr)
      return nullptr;
    auto current = this->root;
    while (current) {
      if (current->data == data) {
        return current;
      } else if (current->data < data) {
        current = current->right;
      } else {
        current = current->left;
      }
    }
    return nullptr;
  };

  Node *findMinimum(Node *current = NULL) {
    if (current == NULL) {
      current = this->root;
    }
    if (current == nullptr)
      return nullptr;
    while (current->left) {
      current = current->left;
    };
    return current;
  }
  Node *findMaximum(Node *current = NULL) {
    if (current == NULL) {
      current = this->root;
    }
    if (current == nullptr)
      return nullptr;
    while (current->right) {
      current = current->right;
    }
    return current;
  }
  Node *insert(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    auto current = this->root;
    while (true) {
      if (!this->root) {
        newNode->parent = nullptr;
        this->root = newNode;
        break;
      }
      if (current->data > data) {
        if (current->left == nullptr) {
          newNode->parent = current;
          current->left = newNode;
          break;
        } else {
          current = current->left;
        }
      } else if (current->data < data) {
        if (current->right == nullptr) {
          newNode->parent = current;
          current->right = newNode;
          break;
        } else {
          current = current->right;
        }
      }
    };
    return newNode;
  };
  void remove(int data) {
    auto nodeToRemove = this->search(data);
    if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr) {
      // if the node have no childe we simply delete it
      delete nodeToRemove;
    } else if (nodeToRemove->left == nullptr ||
               nodeToRemove->right == nullptr) {
      // if node have 1 child
      auto parent = nodeToRemove->parent;
      Node *child;
      if (nodeToRemove->left == nullptr) {
        child = nodeToRemove->right;
      } else {
        child = nodeToRemove->left;
      };
      if (nodeToRemove->data < parent->data) {
        delete nodeToRemove;
        parent->left = child;
      } else {
        delete nodeToRemove;
        parent->right = child;
      }
    } else {
      // if node have 2 childes
      auto nodeToRemove = this->search(data);
      auto replacement = this->findMinimum(nodeToRemove);
      auto parent = nodeToRemove->parent;
      if (nodeToRemove->data > parent->data) {
        parent->right = replacement;
      } else {
        parent->left = replacement;
      };
      replacement->left = nodeToRemove->left;
      replacement->right = nodeToRemove->right;
      if (replacement->parent->data < replacement->data) {
        replacement->parent->right = nullptr;
      } else {
        replacement->parent->left = nullptr;
      };
      replacement->parent = parent;
    }
  }
};

int main() {
  auto tree = new BinarySearchTree();
  tree->insert(1);
  tree->insert(2);
  tree->insert(3);
  tree->insert(4);
  tree->insert(5);
  auto n = tree->search(3);
  std::cout << "the number is " << n->data << std::endl;
  auto max = tree->findMaximum();
  auto min = tree->findMinimum();
  std::cout << "the max value is " << max->data << " and the min value is "
            << min->data << std::endl;
  tree->remove(3);  
}
