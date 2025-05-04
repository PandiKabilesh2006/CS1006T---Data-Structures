//Program to perform all the list ADT operations in the circular singly linked list
#include <cstdio>
#include <cstdlib>
#include <iostream>

class cll{
    private:
    struct node {
        int data;
        struct node *next;
    };
    struct node *head,*tail;

    public:
    cll(){head=tail=NULL;}

    int insertBeg(int);
    int insertEnd(int);
    int insertPos(int,int);
    int delBeg();
    int delEnd();
    int delPos(int);
    int search(int);
    int display();
};

//Main function
int main(){
    cll sll;
    int choice,pos,data;
    while(1){
        printf("Enter 1 to insert in the beginning\n");
        printf("Enter 2 to insert in the end\n");
        printf("Enter 3 to insert in the specified position\n");
        printf("Enter 4 to delete from the beginning\n");
        printf("Enter 5 to delete from the end\n");
        printf("Enter 6 to delete from the specified position\n");
        printf("Enter 7 to search\n");
        printf("Enter 8 to display\n");
        printf("Enter 9 to exit the menu\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            printf("list before insertion in the beginning:");
            sll.display();
            sll.insertBeg(data);
            printf("list after insertion in the beginning:");
            sll.display();
            
            break;
            case 2:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            printf("list before insertion in the end:");
            sll.display();
            sll.insertEnd(data);
            printf("list after insertion in the end:");
            sll.display();
            break;
            case 3:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            printf("Enter the position:");
            scanf("%d",&pos);
            printf("list before insertion in the position:");
            sll.display();
            sll.insertPos(data,pos);
            printf("list after insertion in the position:");
            sll.display();
            break;
            case 4:
            printf("list before delete from the beginning:");
            sll.display();
            sll.delBeg();
            printf("list after deletion from the beginning:");
            sll.display();
            break;
            case 5:
            printf("list before deletion from the end:");
            sll.display();
            sll.delEnd();
            printf("list after deletion from the end:");
            sll.display();
            break;
            case 6:
            printf("Enter the position to be deleted:");
            scanf("%d",&pos);
            printf("list before deletion from the position:");
            sll.display();
            sll.delPos(pos);
            printf("list after deletion from the position:");
            sll.display();
            break;
            case 7:
            printf("Enter the data to be searched:");
            scanf("%d",&data);
            sll.search(data);
            break;
            case 8:
            sll.display();
            break;
            case 9:
            printf("Exiting the menu\n");
            return 0;
            break;
            default:
            printf("Invalid choice entered!!!!!!!!!!!!!!");
        }
    }
}

//Function to insert the node in the beginning of the circular linked list
int cll::insertBeg(int data){
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }
    temp->next=tail->next;
    tail->next=temp;
    return 1;
}

//Function to insert the node in the end of the circular linked list
int cll::insertEnd(int data){
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return 1;
}

//Function to insert the node at the specified position in the circular linked list
int cll::insertPos(int data,int pos){
    struct node *ptr=tail->next;
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    while(pos!=1){
        ptr=ptr->next;
        pos--;

    }
    temp->next=ptr->next;
    ptr->next=temp;
    if(ptr==tail){
        tail=tail->next;
    }
    return 1;

}

//Function to delete the node from the beginning of the circular linked list
int cll::delBeg(){
    if(tail==NULL){
        printf("The Circular Linked List is empty\n");
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    struct node *ptr=tail->next;
    tail->next=ptr->next;
    ptr->next=NULL;
    free(ptr);
    ptr=NULL;
    return 1;
}

//Function to delete the node from the end of the circular singly linked list
int cll::delEnd(){
    if(tail==NULL){
        printf("The Circular Linked List is empty\n");
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    struct node *ptr=tail->next;
    while(ptr->next!=tail){
        ptr=ptr->next;
    }
    ptr->next=tail->next;
    free(tail);
    tail=ptr;
    return 1;

}

//Function to delete the node from the specified position of the circular singly linked list
int cll::delPos(int pos){
    if(tail==NULL){
        printf("The Circular Linked List is empty\n");
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    struct node *ptr=tail->next;
    struct node *ptr2=NULL;
    while(pos!=1){
        ptr2=ptr;
        ptr=ptr->next;
        pos--;
    }
    ptr2->next=ptr->next;
    free(ptr);
    ptr=NULL;
    return 1;

}

//Function to display the values of the nodes of the circular singly linked list
int cll::display(){
    if(tail==NULL){
        printf("Circular linked list is empty\n");
    }
    else{
        struct node *ptr=tail->next;
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        while(ptr!=tail->next);
        printf("\n");
    }
    return 1;

}

//Function to search for the value of the node
int cll::search(int target){
    struct node *ptr=tail->next;
    int index=0;
    do{
        if(ptr->data==target){
            printf("Element found at the index %d\n",index);
        }
        else{
            index++;
        }
        ptr=ptr->next;
    }while(ptr!=tail->next);
    return 1;
}