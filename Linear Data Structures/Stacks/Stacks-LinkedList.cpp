#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push operation to insert an element into the stack
    void push(int value) {
        Node* newNode = new Node(value);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        cout << "Pushed " << value << " into the stack." << endl;
    }

    // Pop operation to remove an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    // Peek operation to see the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Function to display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    return 0;
}
