// C++ Menu-driven to implement Hash ADT using seperate chaining
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define SIZE 10

class Hash{
    private:
    struct node{
        int data;
        struct node* next;
    };
    struct node* head=NULL;
    node* hash[SIZE];
    int hashfunction(int key);
    public:
    Hash();
    void insertion(int key);
    void deletion(int key);
    void search(int key);

    

};

//Main Function
int main(){
    Hash lp;
    int choice,data;
    while(true){
        cout<<"Entering into the Menu\n";
        cout<<"Enter 1 to insert\n";
        cout<<"Enter 2 to delete\n";
        cout<<"Enter 3 to search\n";
        cout<<"Enter 4 to display\n";
        cout<<"Enter 5 to exit\n";

        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the element to be inserted:";
            cin>>data;
            lp.insertion(data);
            break;

            case 2:
            cout<<"Enter the element to be deleted:";
            cin>>data;
            lp.deletion(data);
            break;

            case 3:
            cout<<"Enter the target element to be searched:";
            cin>>data;
            lp.search(data);
            break;


            case 5:
            cout<<"Exiting the Menu!!!";
            return 0;
            break;

            default:
            printf("Invalid choice entered!!!");
            exit(1);

        }

    }
}

//Constructor
Hash::Hash(){
    for(int i=0;i<SIZE;i++){
        hash[i]=NULL;
    }
}

// Function to find the index of the key to be inserted
int Hash::hashfunction(int key){
    return key%SIZE;

}

// Function to insert an element into the Hash Table
void Hash::insertion(int key){
    int index=hashfunction(key);
    struct node* temp=new node;
    temp->data=key;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        hash[index]=head;
        cout<<"Element "<<head->data<<" inserted when the linkedlist is empty"<<endl;
    }
    else{
        temp->next=head;
        head=temp;
        hash[index]=head;
        cout<<"Element "<<head->data<<" inserted at the beginning"<<endl;
    }

}

// Function to delete an element from the Hash Table
void Hash::deletion(int key){
    int index=hashfunction(key);
    int linked_index=0;
    struct node* ptr=head;
    struct node* ptr2=head;
    while(ptr->data!=key){
        ptr2=ptr;
        ptr=ptr->next;
        linked_index++;
    }
    if(ptr==head){
        cout<<"Element "<<head->data<<" deleted successfully from the beginning"<<endl;
        head=head->next;
        hash[index]=head;
        free(ptr);
        ptr=NULL;
    }
    else{
        cout<<"Element "<<ptr->data<<" deleted from the index of the linked list "<<linked_index<<endl;
        ptr2->next=ptr->next;
        free(ptr);
        ptr=NULL;
    }

}

//Function to search for an element in the Hash Table
void Hash::search(int key){
    int index=hashfunction(key);
    struct node* ptr=head;
    while(ptr->data!=key){
        ptr=ptr->next;
    }
    if(ptr->data==key){
        cout<<"Element "<<ptr->data<<" found at the index "<<index<<endl;
    }
    if(ptr==NULL){
        cout<<"Element not found.\n";
    }
}

