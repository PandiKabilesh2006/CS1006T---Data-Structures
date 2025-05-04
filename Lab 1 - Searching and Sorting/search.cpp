#include <cstdio>
#include "sort.h"
//TO PERFORM SEARCH OPERATIONS USING DIFFERENT METHODS
int linearSearch(int arr[],int n,int target);
int binarySearch(int arr[],int n,int target);

//FUNCTION FOR LINEAR SEARCH
int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }

    }
    return -1;
}

//FUNCTION FOR BINARY SEARCH
int binarySearch(int arr[],int n,int target){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    int target,index,choose;
    printf("Enter the number to be searched:");
    scanf("%d",&target);
    printf("\n\nMenu: \nEnter 1 for linear Search \nEnter 2 for Binary Search \nEnter 3 for exit \n");
    int choice;
    printf("Enter your choice:");
    scanf("%d",&choice);
    printf("\n\nMenu: \nEnter 1 for bubble sort \nEnter 2 for selection sort \nEnter 3 for insertion sort \n");
    printf("Enter your choice:");
    scanf("%d",&choose);
    switch(choice){
        case 1:
        index=linearSearch(arr,n,target);
        printf("\nThe element %d is at the index %d\n",target,index);

        break;
        case 2:
        if(choose==1){
            bubbleSort(arr,n);
        }
        else if(choose==2){
            selectionSort(arr,n);
        }
        else{
            insertionSort(arr,n);
        }
        printf("Sorted Array\n");
        printArray(arr,n);
        index=binarySearch(arr,n,target);
        printf("\nThe element %d is at the index %d\n",target,index);
        break;
        case 3:
        return 0;
        break;
        default:
        printf("Invalid choice");
    }
}