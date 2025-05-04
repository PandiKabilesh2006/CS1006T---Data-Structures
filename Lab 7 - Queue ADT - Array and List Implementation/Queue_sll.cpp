#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 5

class Queue{
    private:
    struct node{
        int data;
        struct node *next;
    };
    struct node *front=NULL;
    struct node *rear=NULL;
    int value;

    public:
    int enqueue(int);
    int dequeue();
    int peek();
    int display();
    int isFull();
    int isEmpty();
};

int main(){
    Queue sll;
    int choice,data;
    while(1){
        printf("Enter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for peek\n");
        printf("Enter 4 for exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be enqueue:");
            scanf("%d",&data);
            printf("\nQueue before Enqueue:");
            sll.display();
            sll.enqueue(data);
            printf("\nQueue after Enqueue:");
            sll.display();
            printf("\n\n");
            break;

            case 2:
            printf("\nQueue before Dequeue:");
            sll.display();
            data=sll.dequeue();
            printf("\nQueue after Dequeue:");
            sll.display();
            printf("\nElement dequeued is %d ",data);
            printf("\n\n");
            break;

            case 3:
            data=sll.peek();
            printf("\nThe Front element of the Queue is %d\n\n",data);
            break;

            case 4:
            printf("Exiting the menu!!!!!");
            exit(1);
            break;

            default:
            printf("Invalid Choice Entered!!!!");
            break;
            
        }
    }
}

int Queue::display(){
    if(front==NULL && rear==NULL){
        printf("Queue Underflow\n");
    }
    struct node *ptr=front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 1;
}

int Queue::enqueue(int data){
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=rear->next;
    }
    return 1;
}

int Queue::dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue Underflow\n");
    }
    struct node *temp=front;
    value=front->data;
    front=front->next;
    temp->next=NULL;
    free(temp);
    temp=NULL;
    return value;

}

int Queue::peek(){
    if(front==NULL && rear==NULL){
        printf("Queue Underflow\n");
    }
    return front->data;
}