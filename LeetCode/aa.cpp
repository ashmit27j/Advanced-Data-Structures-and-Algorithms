#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int size;
    int top;
    char* braces; // Changed from string to char array

public:
    // Constructor
    Stack(int capacity = 1000) : size(capacity), top(-1) {
        braces = new char[size];
    }

    // Destructor
    ~Stack() {
        delete[] braces;
        cout << "Stack has been destroyed" << endl;
    }
    
    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Pop the top-most element
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0'; // Return a null character if stack is empty
        }
        return braces[top--];
    }

    // Push an element onto the stack
    void push(char ch) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        braces[++top] = ch;
    }

    // Peek at the top-most element
    char peek() const {
        if (isEmpty()) {
            return '\0'; // Return a null character if stack is empty
        }
        return braces[top];
    }
};

// Function to get the index of the opening brace for a given closing brace
char getOpeningBrace(char closingBrace) {
    switch (closingBrace) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

// Function to check if the braces are balanced
bool isBalanced(const string& str) {
    Stack s(str.length()); // Initialize stack with string length as capacity

    for (char ch : str) {
        // If the character is a closing brace
        char openingBrace = getOpeningBrace(ch);
        if (openingBrace != '\0') {
            // Check if the stack is empty or the top of the stack does not match the closing brace
            if (s.isEmpty() || s.peek() != openingBrace) {
                return false;
            }
            // Pop the matched opening brace
            s.pop();
        } else if (ch == '(' || ch == '[' || ch == '{') {
            // Push the opening brace onto the stack
            s.push(ch);
        }
        // Ignore other characters
    }

    // If the stack is empty, all opening braces had matching closing braces
    return s.isEmpty();
}

int main() {
    string str;
    cout << "Enter a string with braces: ";
    getline(cin, str);

    if (isBalanced(str)) {
        cout << "The braces are balanced.\n";
    } else {
        cout << "The braces are not balanced.\n";
    }

    return 0;
}
