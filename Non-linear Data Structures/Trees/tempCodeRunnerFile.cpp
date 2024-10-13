#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value = 0) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    // Main root node of class Node
    Node* root;

    // Constructor to initialize the root node
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertData(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    void deleteNode(int value) {
        root = deleteNodeRec(root, value);
    }

private:
    Node* insertData(Node* node, int value) {
        // If the tree is empty, create a new node and return it
        if (node == nullptr) {
            return new Node(value);
        }

        // Otherwise, recur down the tree
        if (value < node->data) {
            node->left = insertData(node->left, value);
        } else if (value > node->data) {
            node->right = insertData(node->right, value);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    bool searchRec(Node* node, int value) {
        // Base case: root is null or value is present at root
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }

        // Value is greater than root's data
        if (value < node->data) {
            return searchRec(node->left, value);
        }

        // Value is smaller than root's data
        return searchRec(node->right, value);
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " -> ";
            inOrderTraversal(node->right);
        }
    }

    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to delete a node from the BST
    Node* deleteNodeRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        // Traverse the tree to find the node to be deleted
        if (value < node->data) {
            node->left = deleteNodeRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNodeRec(node->right, value);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteNodeRec(node->right, temp->data);
        }

        return node;
    }
};

int main() {
    BST tree;
    int inp;
    char choice;

    // Inserting nodes into the tree
    // tree.insert(5);
    BST* root = tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Binary Search Tree created with nodes: 5, 3, 7, 2, 4, 6, 8" << endl;
    root.inOrderTraversal();
    cout << endl;

    while (true) {
        cout << "\nOptions:\n";
        cout << "S: Search\n";
        cout << "I: Insert\n";
        cout << "D: Delete\n";
        cout << "P: Print in-order traversal\n";
        cout << "Q: Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'S':
            case 's':
                cout << "Input value to search: ";
                cin >> inp;
                if (tree.search(inp)) {
                    cout << inp << " found in the tree." << endl;
                } else {
                    cout << inp << " not found in the tree." << endl;
                }
                break;

            case 'I':
            case 'i':
                cout << "Input value to insert: ";
                cin >> inp;
                tree.insert(inp);
                cout << inp << " inserted into the tree." << endl;
                break;

            case 'D':
            case 'd':
                cout << "Input value to delete: ";
                cin >> inp;
                tree.deleteNode(inp);
                cout << inp << " deleted from the tree." << endl;
                break;

            case 'P':
            case 'p':
                cout << "In-order Traversal: ";
                tree.inOrderTraversal();
                break;

            case 'Q':
            case 'q':
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }

    return 0;
}
