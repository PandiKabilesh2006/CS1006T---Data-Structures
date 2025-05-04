#include <cstdio>
#include <cstdlib>
#include <cmath>

bool is_palindrome(int *number) {
    int *original = (int *)malloc(sizeof(int));
    int *reversed = (int *)malloc(sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *original = *number;
    *reversed = 0;
    *temp = *number;

    while (*temp > 0) {
        *reversed = (*reversed) * 10 + (*temp % 10);
        *temp /= 10;
    }

    bool result = (*original == *reversed);
    free(original);
    free(reversed);
    free(temp);
    return result;
}

bool is_armstrong(int *number) {
    int *original = (int *)malloc(sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    int *digits = (int *)malloc(sizeof(int));
    *original = *number;
    *temp = *number;
    *sum = 0;
    *digits = 0;

    while (*temp > 0) {
        *temp /= 10;
        (*digits)++;
    }

    *temp = *number;
    while (*temp > 0) {
        *sum += pow(*temp % 10, *digits);
        *temp /= 10;
    }

    bool result = (*sum == *original);
    free(original);
    free(temp);
    free(sum);
    free(digits);
    return result;
}

bool is_perfectNumber(int *number) {
    int *temp = (int *)malloc(sizeof(int));
    int *original = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    *temp = *number;
    *original = *number;
    *sum = 0;
    *count = 1;

    while (*count <= *temp / 2) {
        if (*temp % *count == 0) {
            *sum += *count;
        }
        (*count)++;
    }

    bool result = (*sum == *original);
    free(temp);
    free(original);
    free(sum);
    free(count);
    return result;
}

int main() {
    int *choice = (int *)malloc(sizeof(int));
    int *number = (int *)malloc(sizeof(int));
    if (number == NULL || choice == NULL) {
        printf("Dynamic memory allocation failed");
        return 1;
    }

    printf("\nMenu:\n");
    printf("1. Palindrome\n");
    printf("2. Armstrong Number\n");
    printf("3. Perfect Number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);

    if (*choice == 4) {
        printf("Exiting the menu");
        free(choice);
        free(number);
        return 0;
    }

    printf("Enter the number: ");
    scanf("%d", number);

    switch (*choice) {
        case 1:
            if (is_palindrome(number)) {
                printf("%d is a palindrome number\n", *number);
            } else {
                printf("%d is not a palindrome number\n", *number);
            }
            break;
        case 2:
            if (is_armstrong(number)) {
                printf("%d is an Armstrong number\n", *number);
            } else {
                printf("%d is not an Armstrong number\n", *number);
            }
            break;
        case 3:
            if (is_perfectNumber(number)) {
                printf("%d is a perfect number\n", *number);
            } else {
                printf("%d is not a perfect number\n", *number);
            }
            break;
        case 4:
            printf("Exiting the menu");
            break;
        default:
            printf("The choice entered is incorrect\n");
    }

    free(choice);
    free(number);
    return 0;
}
