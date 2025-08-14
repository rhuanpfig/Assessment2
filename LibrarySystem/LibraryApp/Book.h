#pragma once
#include <string>

// The Book class represents a single book in the library.
// It stores the book's details and provides methods to borrow and return the book.
class Book {
private:
    std::string title;       // Book title
    std::string author;      // Book author
    std::string isbn;        // ISBN identifier (string to preserve leading zeros)
    bool isAvailable;        // Availability flag (true = available, false = borrowed)
    std::string dateAdded;   // Date when the book was added to the library (e.g., "2024-01-01")

public:
    // Default constructor (book is available by default)
    Book();

    // Constructor with parameters
    Book(const std::string& t,
        const std::string& a,
        const std::string& i,
        const std::string& d,
        bool avail = true);

    // Set all book details (with basic validation)
    void setBookDetails(const std::string& t,
        const std::string& a,
        const std::string& i,
        const std::string& d,
        bool avail = true);

    // Display all book details to the console
    void displayBookDetails() const;

    // Borrow the book (returns true if successful)
    bool borrowBook();

    // Return the book (marks it as available)
    void returnBook();

    // Getters (accessor methods)
    const std::string& getISBN() const { return isbn; }
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }
    const std::string& getDateAdded() const { return dateAdded; }
};
