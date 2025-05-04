// C++ Menu-driven Program to implement Hash ADT using Quadratic Probing
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define SIZE 10

class Hash{
    private:
    int hash[SIZE];
    int hashfunction(int key);
    public:
    Hash();
    void insertion(int key);
    void deletion(int key);
    void search(int key);
    void display();

    

};

//Main Function
int main(){
    Hash qp;
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
            qp.insertion(data);
            break;

            case 2:
            cout<<"Enter the element to be deleted:";
            cin>>data;
            qp.deletion(data);
            break;

            case 3:
            cout<<"Enter the target element to be searched:";
            cin>>data;
            qp.search(data);
            break;

            case 4:
            qp.display();
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

// Constructor
Hash::Hash(){
    for(int i=0;i<SIZE;i++){
        hash[i]=-1;
    }
}

// Function to find the index of the key in the Hash Table
int Hash::hashfunction(int key){
    return key%SIZE;

}

// Function to insert an element into the Hash Table
void Hash::insertion(int key){
    int index=hashfunction(key);
    int i=0;

    while(i<SIZE){
        int newIndex=(index+i*i)%SIZE;
        if(hash[newIndex]==-1 || hash[newIndex]==-2){
            hash[newIndex]=key;
            cout<<key<<" inserted at the index "<<newIndex<<" successfully"<<endl;
            return;
        }
        i++;
    }
    cout<<"Hash Table is full. Cannot be inserted.\n";

}

// Function to delete an element from the Hash Table
void Hash::deletion(int key){
    int index=hashfunction(key);
    int i=0;

    while(i<SIZE){
        int newIndex=(index+i*i)%SIZE;
        if(hash[newIndex]==key){
            hash[newIndex]=-2;
            cout<<"Element "<<key<<" Deleted from the index "<<newIndex<<endl;
            return;
        }
        if(hash[newIndex]==-1){
            break;
        }
        i++;
    }
    cout<<"Element not found.\n";

}

// Function to search for an element in the Hash Table
void Hash::search(int key){
    int index=hashfunction(key);
    int i=0;

    while(i<SIZE){
        int newIndex=(index+i*i)%SIZE;
        if(hash[newIndex]==-1){
            break;
        }
        if(hash[newIndex]==key){
            cout<<"Element "<<key<<" found at the index "<<newIndex<<endl;
            return;
        }
        i++;
    }
    cout<<"Element not found.\n";
}

// Function to display all the elements of the Hash Table
void Hash::display(){
    for(int i=0;i<SIZE;i++){
        if(hash[i]==-1){
            cout<<i<<" : Empty\n";
        }
        else if(hash[i]==-2){
            cout<<i<<" : Deleted\n";
        }
        else{
            cout<<i<<" : "<<hash[i]<<endl;
        }
    }

}