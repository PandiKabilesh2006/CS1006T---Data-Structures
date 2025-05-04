//C++ menu-driven program to implement stack ADT using a character array of size 5 and perform the following operations

#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 5

class stack{
    private:
    char value;
    int top=-1;
    char stack_arr[MAX];

    public:
    char push(char);
    char pop();
    char peek();
    void display();

};

//Main Function
int main(){
    stack array;
    int choice;
    char data;
    while(1){
        printf("Enter 1 for Push an element into the stack\n");
        printf("Enter 2 to pop an element from the stack\n");
        printf("Enter 3 to peek the element from the stack\n");
        printf("Enter 4 to Exit the menu\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%s",&data);
            printf("\n");
            printf("The Stack before push operation:");
            array.display();
            array.push(data);
            printf("\nThe Stack after push operation:");
            array.display();
            printf("\nThe element pushed is %c \n",data);
            printf("\n\n");
            break;

            case 2:
            printf("\nThe Stack before pop operation:");
            array.display();
            data=array.pop();
            printf("\nThe Stack after pop operation:");
            array.display();
            printf("\nThe element popped out is %c",data);
            printf("\n\n");
            break;

            case 3:
            data=array.peek();
            printf("\nThe top element of the Stack is %c \n\n",data);
            break;

            case 4:
            printf("Exiting the menu\n");
            return 0;
            break;

            default:
            printf("Invalid Choice Entered\n");
        }
    }
}

//Function to push the element into stack 
char stack::push(char data){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top=top+1;
        stack_arr[top]=data;
        value=data;

    }
    return value;
}

//Function to pop the element from the stack;
char stack::pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        value=stack_arr[top];
        top=top-1;
    }
    return value;
}

//Function to peek the top element from the stack
char stack::peek(){
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        value=stack_arr[top];
    }
    return value;
}

//Function to display the stack
void stack::display(){
    if(top==MAX){
        printf("The Stack is Full\n");
    }
    else if(top==-1){
        printf("The Stack is Empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%c ",stack_arr[i]);
        }
    }
}