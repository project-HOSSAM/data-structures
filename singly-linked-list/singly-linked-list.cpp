#include <iostream>
#include <string>

template<typename N>
struct Node {
    N value;
    Node* next;
};

template<typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    unsigned int length;

public:
    SinglyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    };

    bool isEmpty() {
        return this->head == NULL ? true : false;
    }

    void append(T value) {
        if(this->head == NULL) {
            Node<T>* newNode = new Node<T>();
            newNode->value = value;
            this->head = newNode;
            this->tail = newNode;

            this->length++;
        } else {
            Node<T>* newNode = new Node<T>();
            newNode->value = value;
            newNode->next = NULL;
            this->tail->next = newNode;
            this->tail = newNode;
            this->length++;
        }

    };

    void prepend(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->value = value;
        newNode->next = this->head;
        this->head = newNode; 
        this->length++;
    };

    T shift() {
        Node<T>* temp = this->head;
        T valueTemp = temp->value;
        this->head = this->head->next;
        delete temp;
        this->length--;

        return valueTemp;
    };

    void removeAt(int index) {
        if(index >= this->length && index < 0) return;
        if(index == 0) {
            this->shift();
            return;
        };

        Node<T>* currentNode = this->head;
        int i{};
        for(; i < index - 1; i++) {
            currentNode = currentNode->next;
        };
        Node<T>* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete temp;
        this->length--;
    }

    void remove(T value) {
        Node<T>* currentNode = this->head;
        if(currentNode->value == value) {
            this->shift();
        } else {
            while(currentNode->next) {
                if(currentNode->next->value == value) {
                    Node<T>* temp = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    delete temp;
                    this->length--;
                    break;
                } else {
                    currentNode = currentNode->next;
                };
            };
        }
    };

    void clear() {
        for(int i = this->length; i > 0; i--) {
            Node<T>* currentNode = this->head;
            for(int j = 0; j < i; j++) {
                currentNode = currentNode->next;
            };
            delete currentNode;
            this->length--;
        };
        delete this->head;
    }

    void reverse() {
        if (this->isEmpty()) return;
        Node<T>* currentNode = this->head;
        Node<T>* prevNode;
        Node<T>* temp = this->head;
        for(int i = this->length - 1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            };
            currentNode->next = prevNode;
            currentNode = this->head;
            prevNode = NULL;
        };
        this->head = this->tail;
        this->tail = temp;
    };

    T operator[](int index) {
        Node<T>* currentNode = this->head;
        for(int i = 0; i < index;i++) {
            currentNode = currentNode->next;
        };

        return currentNode->value;
    };

    void log() {
        Node<T>* currentNode = this->head;
        for(int i = 0; i < this->length; i++) {
            std::cout << currentNode->value << ' ';
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    };
};
