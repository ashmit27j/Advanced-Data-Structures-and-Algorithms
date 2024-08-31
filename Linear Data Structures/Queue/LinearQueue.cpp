#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    Queue(int size) {
        capacity = size;
        //declaring front and rear to start at -1
        front = rear = -1;
        //we are assigning the memory of the first element of the array to the pointer queue
        //new is used to allocate memory at runtime
        queue = new int[capacity]; 
    }

    ~Queue() { //destructors are used to deallocate memory
        delete[] queue;
    }

    void enqueue(int item) {
        if (rear == capacity - 1) {
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }

        if (front == -1)
            front = 0;

        queue[++rear] = item;
        cout << "Enqueued element: " << item << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }

        cout << "Dequeued element: " << queue[front++] << endl;

        if (front > rear) //resetting 
            front = rear = -1;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.enqueue(60); // Queue is full
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}