#include <iostream>
#include <string>

using namespace std;

// Book class to represent individual books
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructors to initialize book details
    Book() : title(""), author(""), year(0) {}
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Function to get the book's title
    string getTitle() {
        return title;
    }

    // Function to display the book's details
    void displayBookDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

// Library class to manage a collection of books
class Library {
private:
    Book* books;        // Dynamic array to store books
    int capacity;       // Maximum capacity of the library
    int bookCount;      // Current number of books

    // Function to double the capacity of the books array
    void resizeLibrary() {
        capacity *= 2;
        Book* newBooks = new Book[capacity];
        for (int i = 0; i < bookCount; ++i) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }

public:
    // Constructor to initialize the library with a small capacity
    Library() : capacity(2), bookCount(0) {
        books = new Book[capacity];
    }

    // Destructor to clean up dynamically allocated memory
    ~Library() {
        delete[] books;
    }

    // Function to add a new book to the library
    void addBook(string title, string author, int year) {
        if (bookCount == capacity) {
            resizeLibrary();
        }
        books[bookCount++] = Book(title, author, year);
        cout << "Book added successfully!" << endl;
    }

    // Function to display all books in the library
    void displayAllBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
        } else {
            for (int i = 0; i < bookCount; ++i) {
                cout << "\nBook " << i + 1 << " details:" << endl;
                books[i].displayBookDetails();
            }
        }
    }

    // Function to search for a book by title
    void searchBookByTitle(string title) {
        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getTitle() == title) {
                cout << "Book found!" << endl;
                books[i].displayBookDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    // Menu-driven loop for user interactions
    while (true) {
        cout << "\nLibrary Management System:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the author/s name: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> year;
            library.addBook(title, author, year);
        } else if (choice == 2) {
            library.displayAllBooks();
        } else if (choice == 3) {
            cout << "Enter book title to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBookByTitle(title);
        } else if (choice == 4) {
            cout << "Exiting the program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
