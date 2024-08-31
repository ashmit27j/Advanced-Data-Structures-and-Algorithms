#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int size;
    int top;
    char* stackArray;

public:
    // Constructor
    Stack(int maxSize) {
        size = maxSize;
        top = -1;
        stackArray = new char[size];
    }

    // Destructor
    ~Stack() {
        delete[] stackArray;
        cout << "Stack has been destroyed" << endl;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Push an element onto the stack
    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            stackArray[++top] = ch;
            cout << "Element pushed: " << ch << endl;
        }
    }

    // Pop the topmost element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Element popped: " << stackArray[top--] << endl;
        }
    }

    // Peek at the topmost element without popping it
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return '\0';
        } else {
            cout << "Topmost element: " << stackArray[top] << endl;
            return stackArray[top];
        }
    }
};

// Function to check if the braces in the string are balanced
bool balancedBraces(string str) {
    Stack stk(str.length());

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.isEmpty()) {
                cout << "Unbalanced Braces" << endl;
                return false;
            }
            char topElement = stk.peek();
            if ((ch == ')' && topElement == '(') ||
                (ch == '}' && topElement == '{') ||
                (ch == ']' && topElement == '[')) {
                stk.pop();
            } else {
                cout << "Unbalanced Braces" << endl;
                return false;
            }
        }
    }

    if (stk.isEmpty()) {
        cout << "Balanced Braces" << endl;
        return true;
    } else {
        cout << "Unbalanced Braces" << endl;
        return false;
    }
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    balancedBraces(str);
    return 0;
}







