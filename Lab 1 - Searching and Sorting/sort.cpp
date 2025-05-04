#include <cstdio>
// TO SORT THE ARRAY USING DIFFERENT SORTING METHODS
void bubbleSort(int arr[],int n);
void selectionSort(int arr[],int n);
void insertionSort(int arr[],int n);
void printArray(int arr[],int n);

//FUNCTION FOR BUBBLE SORT
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//FUNCTION FOR SELECTION SORT
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
}

//FUNCTION FOR INSERTION SORT
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }
}

//FUNCTION TO PRINT THE ARRAY
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The array is:");
    printArray(arr,n);
    printf("\n\nMenu: \nEnter 1 for bubble sort \nEnter 2 for selection sort \nEnter 3 for insertion sort \nEnter 4 for exit \n");
    int choice;
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        bubbleSort(arr,n);
        printf("Array sorted using Bubble Sort:");
        printArray(arr,n);
        printf("\n");
        break;
        case 2:
        selectionSort(arr,n);
        printf("Array sorted using Selection Sort:");
        printArray(arr,n);
        printf("\n");
        break;
        case 3:
        insertionSort(arr,n);
        printf("Array sorted using Insertion Sort:");
        printArray(arr,n);
        printf("\n");
        break;
        case 4:
        return 0;
        printf("\n");
        break;
        default:
        printf("Invalid choice!!!");
    }
}