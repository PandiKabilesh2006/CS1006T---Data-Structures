//C++ menu-driven program to implement stack ADT using the singly linked list and perform the following operations

#include <cstdio>
#include <cstdlib>
#include <iostream>

class stack{
    private:
    char value;
    struct node{
        char data;
        struct node *next;
    };
    struct node *head=NULL;

    public:
    stack(){head=NULL;}
    char push(char);
    char pop();
    char peek();
    void display();


};

//Main Function
int main(){
    stack sll;
    int choice;
    char data;

    while(1){
        printf("Enter 1 to push an element into the singly linked list\n");
        printf("Enter 2 to pop an element from the singly linked list\n");
        printf("Enter 3 to peek an element from the singly linked list\n");
        printf("Enter 4 to exit the menu\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%s",&data);
            printf("\nThe Stack before push operation:");
            sll.display();
            sll.push(data);
            printf("\nThe Stack after push operation:");
            sll.display();
            printf("\nThe element pushed is %c",data);
            printf("\n\n");
            break;

            case 2:
            printf("\nThe Stack before pop operation:");
            sll.display();
            data=sll.pop();
            printf("\nThe Stack after pop operation:");
            sll.display();
            printf("\nThe element popped is %c",data);
            printf("\n\n");
            break;

            case 3:
            data=sll.peek();
            printf("\nThe topmost Element of the Stack is %c \n\n",data);
            break;

            case 4:
            printf("Exiting the menu\n");
            return 0;
            break;

            default:
            printf("Invalid choice Entered!!!!!!!\n");
            break;

        }
    }
}

//Function to push an element into stack
char stack::push(char data){
    struct node *temp=new node;
    temp->data=data;

    if(head==NULL){
        temp->next=NULL;
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
        value=head->data;
    }
    return value;

}

//Function to pop the element from the stack
char stack::pop(){
    if(head==NULL){
        printf("The Stack is Empty\n");
    }
    else{
        struct node *ptr=head;
        value=ptr->data;
        head=head->next;
        free(ptr);
        ptr==NULL;
    }
    return value;
}

//Function to peek the topmost element from the stack
char stack::peek(){
    if(head==NULL){
        printf("The Stack is Empty\n");
    }
    else{
        value=head->data;
    }
    return value;
}

//Function to display the Stack
void stack::display(){
    struct node *ptr=head;
    if(head==NULL){
        printf("The Stack is empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("%c ",ptr->data);
            ptr=ptr->next;
        }
    }
}