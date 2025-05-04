#include "Stack.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    Stack s;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) { // Operand
            postfix += ch;
        } else if (ch == '(') { // Left parenthesis
            s.push(ch);
        } else if (ch == ')') { // Right parenthesis
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '('
        } else { // Operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack s;

    for (char ch : postfix) {
        if (isdigit(ch)) { // Operand
            s.push(ch - '0');
        } else { // Operator
            int b = s.pop();
            int a = s.pop();
            switch (ch) {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(a / b); break;
            default: throw runtime_error("Invalid operator");
            }
        }
    }

    return s.pop();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    try {
        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;

        int result = evaluatePostfix(postfix);
        cout << "Evaluation result: " << result << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}