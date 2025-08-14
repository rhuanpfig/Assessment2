#include "Book.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

// Helper function to validate ISBN format (very basic check)
// Allows digits and '-' and requires at least 3 digits
static bool isIsbnLike(const std::string& s) {
    int digits = 0;
    if (s.empty()) return false;
    for (char c : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) digits++;
        else if (c != '-') return false;
    }
    return digits >= 3;
}

// Default constructor
Book::Book() : isAvailable(true) {}

// Parameterized constructor
Book::Book(const std::string& t,
    const std::string& a,
    const std::string& i,
    const std::string& d,
    bool avail) {
    setBookDetails(t, a, i, d, avail);
}

// Sets book details with basic validation
void Book::setBookDetails(const std::string& t,
    const std::string& a,
    const std::string& i,
    const std::string& d,
    bool avail) {
    if (t.empty() || a.empty())
        throw std::invalid_argument("Title/Author cannot be empty");
    if (!isIsbnLike(i))
        throw std::invalid_argument("Invalid ISBN format");
    if (d.size() < 8) // Minimal length check for date (YYYY-MM-DD)
        throw std::invalid_argument("Invalid date format");

    title = t;
    author = a;
    isbn = i;
    dateAdded = d;
    isAvailable = avail;
}

// Displays the book details
void Book::displayBookDetails() const {
    std::cout << "Title: " << title << "\n"
        << "Author: " << author << "\n"
        << "ISBN: " << isbn << "\n"
        << "Date Added: " << dateAdded << "\n"
        << "Status: " << (isAvailable ? "Available" : "Borrowed") << "\n";
}

// Tries to borrow the book
bool Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        std::cout << "Book borrowed successfully.\n";
        return true;
    }
    else {
        std::cout << "Sorry, book already borrowed.\n";
        return false;
    }
}

// Returns the book
void Book::returnBook() {
    isAvailable = true;
}
