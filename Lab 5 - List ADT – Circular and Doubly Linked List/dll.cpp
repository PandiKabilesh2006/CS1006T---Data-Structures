//Program to perform all the List ADT operations in the Doubly Linked List
#include <cstdio>
#include <cstdlib>
#include <iostream>

//Class for the List ADT operations
class dll {
    private:
    struct node{
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head,*tail;

    public:
    dll(){head=tail=NULL;}

    int insertBeg(int);
    int insertEnd(int);
    int insertPosition(int,int);
    int delBeg();
    int delEnd();
    int delPosition(int);
    int search(int);
    int display();
    int reverseDisplay();

};

//Main Function
int main(){
    dll linkedlist;
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
        printf("Enter 9 to display in the reverse order\n");
        printf("Enter 10 to exit the menu\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            linkedlist.insertBeg(data);
            linkedlist.display();
            
            break;
            case 2:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            linkedlist.insertEnd(data);
            linkedlist.display();
            break;
            case 3:
            printf("Enter the data to be inserted:");
            scanf("%d",&data);
            printf("Enter the position:");
            scanf("%d",&pos);
            linkedlist.insertPosition(data,pos);
            linkedlist.display();
            break;
            case 4:
            linkedlist.delBeg();
            linkedlist.display();
            break;
            case 5:
            linkedlist.delEnd();
            linkedlist.display();
            break;
            case 6:
            printf("Enter the position to be deleted:");
            scanf("%d",&pos);
            linkedlist.delPosition(pos);
            linkedlist.display();
            break;
            case 7:
            printf("Enter the data to be searched:");
            scanf("%d",&data);
            linkedlist.search(data);
            break;
            case 8:
            linkedlist.display();
            break;
            case 9:
            linkedlist.reverseDisplay();
            break;
            case 10:
            return 0;
            printf("Exiting the menu!!!!!!");
            break;
            default:
            printf("Invalid choice entered!!!!!!!!!!!!!!");
        }
    }
}

//Function to insert the specific data in the beginning of the doubly linked list.
int dll::insertBeg(int data){
    struct node *temp=new node;
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=data;
    if(head==NULL){
        head=tail=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    return 1;

}

//Function to insert the specific data in the end of the doubly linked list.
int dll::insertEnd(int data){
    struct node *temp=new node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=tail=temp;
        head->prev=NULL;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    return 1;
}

//Function to insert the specific data in the specified position of the doubly linked list.
int dll::insertPosition(int data,int pos){
    if(head==NULL){
        printf("The doubly Linkedlist is empty!!!");
    }
    struct node *temp=new node;
    struct node *ptr=head;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    while(pos!=1){
        ptr=ptr->next;
        pos--;

    }
    struct node *ptr2=ptr->next;
    ptr->next=temp;
    ptr2->prev=temp;
    temp->prev=ptr;
    temp->next=ptr2;
    return 1;
}

//Function to delete the node from the beginning of the doubly linked list.
int dll::delBeg(){
    if(head==NULL){
        printf("The doubly linked list is empty!!!!");
    }
    struct node *ptr=head;
    head=head->next;
    ptr->next=NULL;
    free(ptr);
    ptr=NULL;
    head->prev=NULL;
    return 1;

}
//Function to delete the node from the end of the doubly linked list.
int dll::delEnd(){
    if(tail==NULL){
        printf("The doubly Linkedlist is empty");
    }
    struct node *tem=tail;
    struct node *temp=tail->prev;
    temp->next=NULL;
    free(tem);
    tem=NULL;
    tail=temp;
    return 1;

}

//Function to delete the node from the specified position of the doubly linked list.
int dll::delPosition(int pos){
    if(tail==NULL){
        printf("The doubly linkedlist is empty!");
    }
    struct node *ptr=head;
    while(pos!=1){
        ptr=ptr->next;
        pos--;
    }
    struct node *ptr2=ptr->prev;
    ptr2->next=ptr->next;
    ptr->next->prev=ptr2;
    free(ptr);
    ptr=NULL;
    return 1;

}

//Function to search the specific node of the doubly linked list.
int dll::search(int data){
    struct node *ptr=head;
    int index=0;
    while(ptr!=NULL){
        if(ptr->data==data){
            printf("The element found at the index %d\n",index);

        }
        else{
            index++;
        }
        ptr=ptr->next;
    }
    return 1;

}

//Function to display the nodes of the doubly linked list.
int dll::display(){
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return 1;

}
//Function to display the nodes of the doubly linked list in the reverse order.
int dll::reverseDisplay(){
    struct node *ptr=tail;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
    return 1;
}