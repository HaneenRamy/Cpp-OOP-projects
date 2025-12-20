#include <iostream>
#include <vector>
#include <string>

using namespace std;

// LibrarySystem class manages all library-related operations
class LibrarySystem {
private:
    // Stores books that are available in the library
    vector<string> availableBooks;

    // Stores books that have been borrowed
    vector<string> borrowedBooks;

public:
    // Constructor: initializes the library with some books
    LibrarySystem() {
        availableBooks.push_back("The Hundred Years' War On Palestine");
        availableBooks.push_back("I saw Ramallah");
        availableBooks.push_back("Harry Potter");
        availableBooks.push_back("The Lord Of The Rings");
        availableBooks.push_back("Little Women");
        availableBooks.push_back("Atomic Habits");
        availableBooks.push_back("Alchemist");
        availableBooks.push_back("1984");
        availableBooks.push_back("The Great Gatsby");
        availableBooks.push_back("Psychology Of Money");
    }

    // Displays the main menu
    void displayMenu() {
        cout << "\n--- Library Management System Menu ---" << endl;
        cout << "1. View Available Books" << endl;
        cout << "2. Borrow a Book" << endl;
        cout << "3. Return a Book" << endl;
        cout << "4. View Borrowed Books" << endl;
        cout << "5. Add a New Book" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
    }

    // Displays all available books
    void viewAvailableBooks() {
        cout << "\n--- Available Books ---" << endl;

        if (availableBooks.empty()) {
            cout << "No books are currently available." << endl;
        }
        else {
            for (int i = 0; i < availableBooks.size(); i++) {
                cout << i + 1 << ". " << availableBooks[i] << endl;
            }
        }
    }

    // Allows the user to borrow a book
    void borrowBook() {
        cout << "\n--- Borrow a Book ---" << endl;
        viewAvailableBooks();

        if (availableBooks.empty())
            return;

        cout << "\nEnter the number of the book you want to borrow: ";
        int choice;
        cin >> choice;

        // Input validation
        if (cin.fail() || choice < 1 || choice > availableBooks.size()) {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        // Move selected book from available to borrowed
        string bookToBorrow = availableBooks[choice - 1];
        borrowedBooks.push_back(bookToBorrow);
        availableBooks.erase(availableBooks.begin() + (choice - 1));

        cout << "\"" << bookToBorrow << "\" has been successfully borrowed." << endl;
    }

    // Allows the user to return a borrowed book
    void returnBook() {
        cout << "\n--- Return a Book ---" << endl;
        viewBorrowedBooks();

        if (borrowedBooks.empty())
            return;

        cout << "\nEnter the number of the book you want to return: ";
        int choice;
        cin >> choice;

        // Input validation
        if (cin.fail() || choice < 1 || choice > borrowedBooks.size()) {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        // Move selected book from borrowed to available
        string bookToReturn = borrowedBooks[choice - 1];
        availableBooks.push_back(bookToReturn);
        borrowedBooks.erase(borrowedBooks.begin() + (choice - 1));

        cout << "\"" << bookToReturn << "\" has been successfully returned." << endl;
    }

    // Displays all borrowed books
    void viewBorrowedBooks() {
        cout << "\n--- Borrowed Books ---" << endl;

        if (borrowedBooks.empty()) {
            cout << "You have no books borrowed at the moment." << endl;
        }
        else {
            for (int i = 0; i < borrowedBooks.size(); i++) {
                cout << i + 1 << ". " << borrowedBooks[i] << endl;
            }
        }
    }
    // Adds a new book to the library
    void addBook() {
        cout << "\n--- Add a New Book ---" << endl;
        cout << "Enter the title of the new book: ";

        cin.ignore();
        string newBookTitle;
        getline(cin, newBookTitle);

        if (!newBookTitle.empty()) {
            availableBooks.push_back(newBookTitle);
            cout << "\nThe book \"" << newBookTitle << "\" has been added successfully." << endl;
        }
        else {
            cout << "Invalid book title." << endl;
        }
    }

    // Runs the main program loop
    void start() {
        int option;

        do {
            displayMenu();
            cin >> option;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            switch (option) {
            case 1: viewAvailableBooks(); break;
            case 2: borrowBook(); break;
            case 3: returnBook(); break;
            case 4: viewBorrowedBooks(); break;
            case 5: addBook(); break;
            case 6:
                cout << "\nExiting the system. Thank you for using it!" << endl;
                break;
            default:
                cout << "Please enter a valid option (1–6)." << endl;
            }

        } while (option != 6);
    }
};

int main() {
    LibrarySystem library;
    library.start();
    return 0;
}
