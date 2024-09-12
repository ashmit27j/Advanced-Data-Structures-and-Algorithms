#include <iostream>
using namespace std;

// Node class to represent each element in the queue
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation to insert an element at the rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            cout << "Enqueued " << value << " into the queue." << endl;
        } else {
            rear->next = newNode;
            rear = newNode;
            cout << "Enqueued " << value << " into the queue." << endl;
        }
    }

    // Dequeue operation to remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        // If the queue becomes empty after dequeue
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued " << temp->data << " from the queue." << endl;
        delete temp;
    }

    // Peek operation to see the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to demonstrate queue operations
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}
