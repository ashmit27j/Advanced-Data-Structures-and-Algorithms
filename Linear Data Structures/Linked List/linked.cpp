// Function to insert a new node at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a new node at a specific position (0-based index)
void insertAtPosition(Node*& head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);
    cout << "Linked list after inserting at the beginning: ";
    displayList(head);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << "Linked list after inserting at the end: ";
    displayList(head);

    insertAtPosition(head, 25, 2);
    cout << "Linked list after inserting at position 2: ";
    displayList(head);

    return 0;
}
