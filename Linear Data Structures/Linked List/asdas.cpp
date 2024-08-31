// Function to delete a node at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node at the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
}

// Function to delete a node at a specific position (0-based index)
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtPosition(head, 25, 2);
    cout << "Linked list before deletions: ";
    displayList(head);

    deleteAtBeginning(head);
    cout << "Linked list after deleting at the beginning: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "Linked list after deleting at the end: ";
    displayList(head);

    deleteAtPosition(head, 1);
    cout << "Linked list after deleting at position 1: ";
    displayList(head);

    return 0;
}
