// C++ menu-driven program to implement Hash ADT with Linear Probing
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

            case 4:
            lp.display();
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
        hash[i]=-1;
    }
}

// Function to find the index of the element in the Hash Table
int Hash::hashfunction(int key){
    return key%SIZE;

}

// Function to insert an element an element into the Hash Table
void Hash::insertion(int key){
    int index=hashfunction(key);
    int start=index;

    while(hash[index]!=-1 && hash[index]!=-2){
        index=(index+1)%SIZE;
        if(start==index){
            cout<<"The Hash Table is full"<<endl;
            return;
        }
    }
    hash[index]=key;
    cout<<key<<" inserted at the position "<<index<<" successfully"<<endl;

}

// Function to delete an element from the Hash Table
void Hash::deletion(int key){
    int index=hashfunction(key);
    int start=index;
    while(hash[index]!=-1){
        if(hash[index]==key){
            hash[index]=-2;
            cout<<"Deleted "<<key<<" from the index"<< index<<endl;
            return;
        }
        index=(index+1)%SIZE;
        if(start==index){
            break;
        }
    }
    cout<<"Element not found.\n"<<endl;

}

// Function to search and find the index of the element from the Hash Table
void Hash::search(int key){
    int index=hashfunction(key);
    int start=index;

    while(hash[index]!=-1){
        if(hash[index]==key){
            cout<<"Element "<<key<<" found at the index "<<index<<endl;
            return;
        }
        index=(index+1)%SIZE;
        if(start==index){
            break;
        }
    }
    cout<<"Element not found.\n"<<endl;
}

// Function to display the Hash Table
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