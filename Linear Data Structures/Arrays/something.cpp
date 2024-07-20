//Code as a librarian to delete and add books when needed and update their values for issued or not issude, boolean format flag
#include <iostream>
#include <string>
using namespace std;

class Library {
    private:
        string bookName;
        float bookCost;
        bool issuedStatus;
        int serialNumber;

    public:
        // Default constructor to initialize values
        Library() : bookName(""), bookCost(0.0), issuedStatus(false), serialNumber(0) {}

        // Parameterized constructor initiliazed when an object is created
        Library(string name, float cost, bool status, int serial)
            : bookName(name), bookCost(cost), issuedStatus(status), serialNumber(serial) {}

        // Function to input book details, called when user wishes to add a new group
        void inputBookDetails() {
            cout << "Enter book name: ";
            cin.ignore();
            getline(cin, bookName);
            cout << "Enter book cost: ";
            cin >> bookCost;
            cout << "Is the book issued? (1 for Yes, 0 for No): ";
            cin >> issuedStatus;
            cout << "Enter serial number: ";
            cin >> serialNumber;
        }

        // Function to display book details of all the books
        void displayAllBooks(Library books[], int size){
            for(int i = 0; i < n; i++ ){
                cout << "Book Name: " << books[i].bookName << endl;
                cout << "Book Cost: " << books[i].bookCost << endl;
                cout << "Issued Status: " << (books[i].issuedStatus ? "Issued" : "Not Issued") << endl;
                cout << "Serial Number: " << books[i].serialNumber << endl;
            }
        }
        // Function to display book details when the librarian wishes to see details about a specific serial number
        void displaySpecificBook(){
            int userInput;
            cout << "Please enter your book serial number: ";
            cin >> userInput;
            for(int i = 0; )
        }

        // Search for a book that you want
        Books displaySpecificBook(Library books[], int low, int high, int ele){
            while(low <= high){
                int mid = low + (high - low)/2;
            }
            if(books[mid].serialNumber == ele){
                return books[i];
            }
            else if(books[mid].serialNumber < ele){
                displaySpecificBook(books[], mid + 1, high, ele)
            }
            else{
                displaySpecificBook(books[], low, mid - 1, ele)
            }
            return -1;
        }
        void insertAtPosition();
        void insertAtStart();
        void insertAtEnd();
        void deleteAtStart();
        void deleteAtEnd();
        void deleteAtPosition();
};

int main() {
    int n, choice;
    cout << "Enter the number of books: ";
    cin >> n;

    // Create an array of Book objects
    Library books[n];

    // Input details for each book
    for (int i = 0; i < n; ++i) {
        cout << "\nEntering details for book number " << i + 1 << ":\n";
        books[i].inputBookDetails();
    }

    cout << "\nEnter your choice:\n1. Display all the books\n2. Display specific book\n3. Insert at position\n4. Insert at start\n5. Insert at end\n6. Delete at start\n7. Delete at end\n8. Delete at position";
    cin >> choice;

    switch (choice)
    {

    case 1:
        Library.displayAllBooks(books, n);
        break;
    case 2:
        Library.displaySpecificBook();
        break;
    case 3:
        Library.insertAtPosition();
        break;
    case 4:
        Library.insertAtStart();
        break;
    case 5:
        Library.insertAtEnd();
        break;
    case 6:
        Library.deleteAtStart();
        break;
    case 7:
        Library.deleteAtEnd();
        break;
    case 8:
        Library.deleteAtPosition();
        break;
    default:
        cout << "\nInvalid Input";
        break;
    }

    // Display details of all books
    cout << "\nDisplaying details of all books:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nBook " << i + 1 << " details:\n";
        books[i].displayBookDetails();
    }

    // Print specific book data
    cout << "\nPlease enter serial number of the book:"

    return 0;
}