#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to swap two nodes in the linked list
bool swap(Node*& head, int x, int y) {
    if (x == y) return true;

    Node *prevX = nullptr, *currX = head;
    Node *prevY = nullptr, *currY = head;

    // Find x in the list
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Find y in the list
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, return false
    if (!currX || !currY) return false;

    // If x is not the head of the list
    if (prevX) {
        prevX->next = currY;
    } else {
        head = currY;
    }

    // If y is not the head of the list
    if (prevY) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return true;
}

// Function to push a new node at the head of the list
void push(Node*& head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the swap algorithm
int main() {
    Node* head = nullptr;

    // Creating a linked list 10 -> 15 -> 12 -> 13 -> 20 -> 14
    push(head, 14);
    push(head, 20);
    push(head, 13);
    push(head, 12);
    push(head, 15);
    push(head, 10);

    cout << "Original list: ";
    printList(head);

    // Swap nodes with data 12 and 20
    if (swap(head, 12, 20)) {
        cout << "List after swapping 12 and 20: ";
        printList(head);
    } else {
        cout << "Swap failed." << endl;
    }

    // Swap nodes with data 10 and 14 (head and tail)
    if (swap(head, 10, 14)) {
        cout << "List after swapping 10 and 14: ";
        printList(head);
    } else {
        cout << "Swap failed." << endl;
    }

    // Attempt to swap nodes with data 12 and 99 (nonexistent node)
    if (swap(head, 12, 99)) {
        cout << "List after swapping 12 and 99: ";
        printList(head);
    } else {
        cout << "Swap failed (99 not found)." << endl;
    }

    return 0;
}
