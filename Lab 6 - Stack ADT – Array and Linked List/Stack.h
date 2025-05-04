//Header file to implement the infix and postfix and evaluate 
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char val) {
        Node* newNode = new Node{val, top};
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        Node* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
