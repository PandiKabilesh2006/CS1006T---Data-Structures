//TO check the given equation is balanced or not
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(const string& str) {
    Stack stack;

    for (char ch : str) {
        if (ch == '(') {
            stack.push(ch); 
        } else if (ch == ')') {
            if (stack.isEmpty()) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}

int main() {
    int choice;
    string input;

    do {
        cout << "Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> input;
                if (isBalanced(input)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are not balanced.\n";
                }
                break;

            case 2:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}