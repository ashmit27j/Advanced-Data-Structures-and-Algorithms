#include <iostream>

using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    //constructor
    Queue(int capacity) {
        size = capacity;
        front = rear = -1;
        arr = new int[size];
    }

    //destructor
    ~Queue() {
        delete[] arr;
    }

    //to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    //to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }
    
    //to add an element to the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
        arr[rear] = item;
        cout << item << " enqueued element." << endl;
    }

    //to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int item = arr[front];
        if (front == rear) //reset them back to -1
            front = rear = -1;
        else    //formula to move front to the next element
            front = (front + 1) % size;

        cout << item << " dequeued from the queue." << endl;
    }

    //to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);

    int choice, item;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}