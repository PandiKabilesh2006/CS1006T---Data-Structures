// Menu-driven c++ program to implement Queue ADT  using Array and perform the follwing Operations
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 5

class Queue{
    private:
    int queue_arr[MAX];
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

//Main Function
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

// Function to display the elements of the Queue
int Queue::display(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue_arr[i]);
    }
    return 1;

}

// Function to add a element into the Queue
int Queue::enqueue(int data){
    if(isFull()){
        printf("Queue Overflow\n");
    }
    if(front==-1){
        front=0;
    }
    rear++;
    queue_arr[rear]=data;
    return 1;
}

//Function to delete an element from the Queue
int Queue::dequeue(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    value=queue_arr[front];
    front++;
    return value;

}

//Function to return the front element of the Queue
int Queue::peek(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    return queue_arr[front];
}

// Function to check the emptiness of the Queue
int Queue::isEmpty(){
    if(front==-1||front==rear+1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check the Fullness of the Queue
int Queue::isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

