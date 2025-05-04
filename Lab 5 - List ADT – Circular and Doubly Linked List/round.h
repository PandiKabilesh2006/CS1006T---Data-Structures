//The header file to do the round robin
#include <stdio.h>
#include <stdlib.h>

class list {
    struct Node {
        int time;
        Node* next;
    } *tail;
    int fixedTime;

public:
    list(int ft) : tail(NULL), fixedTime(ft) {}

    void insertProcess(int t);

    void execute() ;
};


//To insert the task and the time required to do the task
void list ::insertProcess(int t) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->time = t;
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}


//To execute the task
void list:: execute() {
    if (!tail) {
        printf("No processes to execute.\n");
        return;
    }

    Node* head = tail->next;
    printf("Executing process with time: %d\n", head->time);
    head->time -= fixedTime;

    if (head->time <= 0) {
        printf("Process completed.\n");
        if (head == tail) {
            free(head);
            tail = NULL;
        } else {
            tail->next = head->next;
            free(head);
        }
    } else {
        printf("Process reinserted with remaining time: %d\n", head->time);
        tail->next = head->next;
        head->next = tail->next;
        tail->next = head;
        tail = head;
    }
}