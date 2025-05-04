//C++ menu-driven program to implement Priority Queue ADT using max heap

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// class
class heap{
    private:
    vector<int>heap;

    public:
    void insert(int num);
    void deleteMax();
    void display();
    void search(int num);
    void heapsort();
};

//Main Function
int main(){
    heap pq;
    int choice,num;
    while(1){
        cout<<"Heap menu\n";
        cout<<"Enter 1 for insert\n";
        cout<<"Enter 2 for Delete\n";
        cout<<"Enter 3 for Display\n";
        cout<<"Enter 4 for Search\n";
        cout<<"Enter 5 for Heap Sort\n";
        cout<<"Enter 6 for exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the element to be inserted:";
            cin>>num;
            pq.insert(num);
            break;

            case 2:
            pq.deleteMax();
            break;

            case 3:
            pq.display();
            break;

            case 4:
            cout<<"Enter the element to be searched:";
            cin>>num;
            pq.search(num);
            break;

            case 5:
            cout<<"Sorted Heap"<<endl;
            pq.heapsort();
            break;

            case 6:
            cout<<"Exiting the menu";
            exit(1);
            break;

            default:
            cout<<"Invalid choice entered!!!";

        }


    }
    return 0;
}

// Function to insert elements and heapify up for the max heap
void heap::insert(int num){
    heap.push_back(num);
    int index=heap.size()-1;
    while(index>0){
        int parent=(index-1)/2;
        if(heap[index]>heap[parent]){
            swap(heap[index],heap[parent]);
            index=parent;
        }
        else{
            break;
        }
    }
    cout<<num<<" inserted successfully at the max heap\n";
    return;
}

// Heapify down function to delete max element
void heap::deleteMax(){
    if(heap.empty()){
        cout<<"Heap is empty"<<endl;
        return;
    }

    cout<<heap[0]<<" is the deleted element"<<endl;

    heap[0]=heap.back();
    heap.pop_back();
    int size=heap.size();
    int index=0;
    while(index<size){
        int left=2*index+1;
        int right=2*index+2;
        int largest=index;
        if(left<size && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<size && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(heap[index],heap[largest]);
            index=largest;
        }
        else{
            break;
        }
    }

}

// Function to display elements of the max heap
void heap::display(){
    if(heap.empty()){
        cout<<"Heap is empty"<<endl;
        return;
    }
    int size=heap.size();
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }
}

// Function to search element in the max heap
void heap::search(int num){
    int size=heap.size();
    for(int i=0;i<size;i++){
        if(heap[i]==num){
            cout<<heap[i]<<" found at the index "<<i<<endl;
            return;
        }
    }

}

// Function to heap all the elements using heapsort
void heap::heapsort(){
    vector<int>tempheap=heap;
    vector<int>sorted;

    while(!tempheap.empty()){
        sorted.push_back(tempheap[0]);
        tempheap[0]=tempheap.back();
        tempheap.pop_back();

        int index=0;
        int size=tempheap.size();
        while(index<size){
            int left=2*index+1;
            int right=2*index+2;
            int largest=index;

            if(left<size && tempheap[left]>tempheap[largest]){
                largest=left;
            }
            if(right<size && tempheap[right]>tempheap[largest]){
                largest=right;
            }
            if(largest!=index){
                swap(tempheap[index],tempheap[largest]);
                index=largest;
            }
            else{
                break;
            }

        }

    }
    for(int i=0;i<sorted.size();i++){
        cout<<sorted[i]<<" ";
    }


}
