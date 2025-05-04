#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 5

class Queue{
    private:
    int cqueue[MAX];
    int value;
    int front=-1;
    int rear=-1;

    public:
    int enqueue(int);
    int dequeue();
    int peek();
    int display();
    int isFull();
    int isEmpty();
};

int main(){
    Queue arr;
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
            arr.display();
            arr.enqueue(data);
            printf("\nQueue after Enqueue:");
            arr.display();
            printf("\n\n");
            break;

            case 2:
            printf("\nQueue before Dequeue:");
            arr.display();
            data=arr.dequeue();
            printf("\nQueue after Dequeue:");
            arr.display();
            printf("\nElement dequeued is %d ",data);
            printf("\n\n");
            break;

            case 3:
            data=arr.peek();
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
    int temp;
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    temp=front;
    if(front<=rear){
        while(temp<=rear){
            printf("%d ",cqueue[temp]);
            temp++;
        }
    }
    else{
        while(temp<=MAX-1){
            printf("%d ",cqueue[temp]);
            temp++;
        }
        temp=0;
        while(temp<=rear){
            printf("%d ",cqueue[temp]);
            temp++;
        }
    }
    return 1;

}

int Queue::enqueue(int data){
    if(isFull()){
        printf("Queue Overflow\n");
    }
    if(front==-1){
        front=0;
    }
    if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
        cqueue[rear]=data;
    }
    return 1;
}

int Queue::dequeue(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    value=cqueue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
    return value;

}

int Queue::peek(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    return cqueue[front];
}

int Queue::isEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Queue::isFull(){
    if((front==0 && rear==MAX-1)||(front==rear+1)){
        return 1;
    }
    else{
        return 0;
    }
}