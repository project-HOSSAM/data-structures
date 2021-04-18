#include <iostream>
#include <functional>
#include <vector>

template <typename T>
struct Node
{
    Node *left;
    Node *right;
    T value;
};

template <typename T>
class BinarySearchTree
{
private:
    Node<T> *root;

public:
    BinarySearchTree()
    {
        this->root = nullptr;
    }
    BinarySearchTree(T value)
    {
        Node<T> *newNode = new Node();
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        this->root = newNode;
    }
    void insert(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (this->root == nullptr)
        {
            this->root = newNode;
        }
        else
        {
            Node<T> *currentNode = this->root;
            while (true)
            {
                if (value < currentNode->value)
                {
                    // left
                    if (!currentNode->left)
                    {
                        currentNode->left = newNode;
                        return;
                    }
                    currentNode = currentNode->left;
                }
                else
                {
                    // right
                    if (!currentNode->right)
                    {
                        currentNode->right = newNode;
                        return;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

    std::vector<T> inOrder()
    {
        std::vector<T> result;
    }

    bool lookup(T value)
    {
        if (!this->root)
        {
            return false;
        }
        Node<T> *currentNode = this->root;
        while (currentNode)
        {
            if (currentNode->value > value)
            {
                currentNode = currentNode->left;
            }
            else if (currentNode->value < value)
            {
                currentNode = currentNode->right;
            }
            else if (currentNode->value == value)
            {
                return true;
            }
        };
        return false;
    }
};