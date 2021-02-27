#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        unsigned int length;
    public:
        void append(int value);
        void prepend(int value);
        bool lookup(int value) const;
        void insert(int value, unsigned int position);
        void remove(int value);
        void pop();
        void shift();
        int indexOf(int value) const;
        void log() const;
};  

void LinkedList::append(int value) {
    if(!this->head) {
        Node* newNode = new Node();
        newNode->data = value;
        this->head = newNode;
        this->length++;
    } else {
        Node* currentNode = this->head;
        while(currentNode->next) {
            currentNode = currentNode->next;
        };
        
        Node* newNode = new Node();
        newNode->data = value;
        currentNode->next = newNode;
        this->length++;
    }
};

void LinkedList::prepend(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = this->head;
    this->head = newNode;
    this->length++;
};

void LinkedList::insert(int value, unsigned int position) {
    if(position == 0 ) {
        this->prepend(value);
        return;
    }
    if(position >= this->length) return;
    Node* newNode = new Node();
    Node* currentNode = this->head;
    unsigned int i{};
    for(; i< position; i++) {
        currentNode = currentNode->next;
    };
    newNode->data = value;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    this->length++;
};

bool LinkedList::lookup(int value) const {
    Node* currentNode = this->head;
    unsigned int i{};
    for(; i < this->length; i++) {
        if(currentNode->data == value) {
            return true;
        };
        currentNode = currentNode->next;
    };
    return false;
};

void LinkedList::pop() {
    Node* currentNode = this->head;
    while(currentNode->next) {
        currentNode = currentNode->next;
    };
    delete currentNode;
    this->length--;
};

void LinkedList::shift() {
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->length--;
}

void LinkedList::remove(int index) {

    if(index == 0) {
        this->shift();
        return;
    };

    if(index == this->length - 1) {
        this->pop();
        return;
    };

    Node* currentNode = this->head;
    unsigned int i{};
    for(; i < index - 1; i++) {
        currentNode = currentNode->next;
    };
    currentNode->next = currentNode->next->next;
    delete currentNode->next;
    this->length--;
};

int LinkedList::indexOf(int value) const {
    Node* currentNode = this->head;
    unsigned int i{};
    for(; i < this->length; i++) {
        if(currentNode->data == value) {
            return i;
        };

        currentNode = currentNode->next;
    };

    return -1;
};


void LinkedList::log() const {
    Node* currentNode = this->head;
    for(int i = 0; i < this->length; i++) {
        std::cout << currentNode->data << ' ';
        currentNode = currentNode->next;
    };
    std::cout << std::endl;
};