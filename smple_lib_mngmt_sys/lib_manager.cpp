#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Define the Book class to represent individual books.
class Book {
private:
    std::string title;     // Private member variable for the title of the book.
    std::string author;    // Private member variable for the author of the book.
    std::string isbn;      // Private member variable for the ISBN of the book.

public:
    // Constructor that initializes the book with a title, author, and ISBN.
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Getter function to retrieve the title of the book.
    std::string getTitle() const { return title; }

    // Getter function to retrieve the author of the book.
    std::string getAuthor() const { return author; }

    // Getter function to retrieve the ISBN of the book.
    std::string getISBN() const { return isbn; }
};

// Define the User class to represent individual library users.
class User {
private:
    std::string name;                   // Private member variable for the name of the user.
    std::vector<Book> borrowedBooks;    // List of books that the user has borrowed.

public:
    // Constructor that initializes the user with a name.
    User(const std::string& name) : name(name) {}

    // Member function for a user to borrow a book. The book is added to the user's borrowedBooks list.
    void borrowBook(const Book& book) {
        borrowedBooks.push_back(book);
    }

    // Member function for a user to return a book based on its ISBN.
    void returnBook(const std::string& isbn) {
        borrowedBooks.erase(
            // Use the remove_if algorithm to remove the book with the given ISBN.
            std::remove_if(borrowedBooks.begin(), borrowedBooks.end(),
                           [&](const Book& b) { return b.getISBN() == isbn; }),
            borrowedBooks.end());
    }

    // Display all the books borrowed by the user.
    void displayBorrowedBooks() const {
        std::cout << name << " has borrowed the following books:\n";
        for (const auto& book : borrowedBooks) {
            std::cout << "- " << book.getTitle() << " by " << book.getAuthor() << "\n";
        }
    }

    // Getter function to retrieve the name of the user.
    std::string getName() const { return name; }
};

// Define the Library class to represent the library.
class Library {
private:
    std::vector<Book> books;  // List of all books in the library.
    std::vector<User> users;  // List of all users registered in the library.

public:
    // Add a book to the library's collection.
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Register a user in the library.
    void addUser(const User& user) {
        users.push_back(user);
    }

    // Find a user based on their name and return a pointer to the user. Return nullptr if not found.
    User* findUser(const std::string& name) {
        for (auto& user : users) {
            if (user.getName() == name) {
                return &user;
            }
        }
        return nullptr;
    }

    // Find a book based on its ISBN and return a pointer to the book. Return nullptr if not found.
    Book* findBook(const std::string& isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                return &book;
            }
        }
        return nullptr;
    }

    // Display all the books available in the library.
    void displayBooks() const {
        std::cout << "Books in the library:\n";
        for (const auto& book : books) {
            std::cout << "- " << book.getTitle() << " by " << book.getAuthor() << "\n";
        }
    }
};

// Main function to demonstrate the functionality.
int main() {
    Library myLibrary;

    // Add books to the library.
    myLibrary.addBook(Book("Dune", "Frank Herbert", "123456"));
    myLibrary.addBook(Book("1984", "George Orwell", "789101"));

    // Register users in the library.
    myLibrary.addUser(User("Alice"));
    myLibrary.addUser(User("Bob"));

    // Let Alice borrow the book "Dune".
    User* alice = myLibrary.findUser("Alice");
    Book* dune = myLibrary.findBook("123456");
    if (alice && dune) {
        alice->borrowBook(*dune);
    }

    // Display the books borrowed by Alice.
    alice->displayBorrowedBooks();

    // Display all the books in the library.
    myLibrary.displayBooks();

    return 0;
}
