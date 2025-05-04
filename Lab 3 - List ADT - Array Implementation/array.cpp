#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX_SIZE 5

class Array {
private:
    int arr[MAX_SIZE];
    int size = 0;

public:
    int insertBeginning(int);
    int insertEnd(int);
    int insertPosition(int, int);
    int deleteBeginning();
    int deleteEnd();
    int deletePosition(int);
    int search(int);
    int display();
    int rotate(int);
    int reverse(int, int);
};

int main() {
    Array array;
    int choice, value, pos, k;

    while (1) {
        printf("\nEnter 1 to insert at the Beginning\n");
        printf("Enter 2 to insert at the End\n");
        printf("Enter 3 to insert at a Position\n");
        printf("Enter 4 to Delete from Beginning\n");
        printf("Enter 5 to Delete from End\n");
        printf("Enter 6 to Delete from a Position\n");
        printf("Enter 7 to Search\n");
        printf("Enter 8 to Display\n");
        printf("Enter 9 to Rotate\n");
        printf("Enter 10 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                array.insertBeginning(value);
                array.display();
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                array.insertEnd(value);
                array.display();
                break;
            case 3:
                printf("Enter the position and value: ");
                scanf("%d %d", &pos, &value);
                array.insertPosition(pos, value);
                array.display();
                break;
            case 4:
                array.deleteBeginning();
                array.display();
                break;
            case 5:
                array.deleteEnd();
                array.display();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                array.deletePosition(pos);
                array.display();
                break;
            case 7:
                printf("Enter the value: ");
                scanf("%d", &value);
                array.search(value);
                array.display();
                break;
            case 8:
                array.display();
                break;
            case 9:
                printf("Enter k: ");
                scanf("%d", &k);
                array.rotate(k);
                array.display();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice Entered!!!!\n");
        }
    }
}

int Array::insertBeginning(int value) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return 0;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    return 1;
}

int Array::insertEnd(int value) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return 0;
    }
    arr[size++] = value;
    return 1;
}

int Array::insertPosition(int pos, int value) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return 0;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid Position\n");
        return 0;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    return 1;
}

int Array::deleteBeginning() {
    if (size == 0) {
        printf("Array is empty\n");
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return 1;
}

int Array::deleteEnd() {
    if (size == 0) {
        printf("Array is empty\n");
        return 0;
    }
    size--;
    return 1;
}

int Array::deletePosition(int pos) {
    if (size == 0) {
        printf("Array is empty\n");
        return 0;
    }
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return 1;
}

int Array::search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element %d found at index %d\n", value, i);
            return 1;
        }
    }
    printf("Element not found\n");
    return 0;
}

int Array::display() {
    if (size == 0) {
        printf("Array is empty\n");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}

int Array::reverse(int start, int end) {
    if (start < 0 || end >= size || start >= end) {
        return 0;
    }
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return 1;
}

int Array::rotate(int k) {
    if (size == 0) {
        printf("Array is empty\n");
        return 0;
    }
    k = k % size;
    if (k == 0) {
        return 1;
    }
    reverse(0, size - 1);
    reverse(0, k - 1);
    reverse(k, size - 1);
    return 1;
}

