#include <iostream>
#include <vector>
#include "Book.h"
#include "Sort.h"

// Helper function to print book arrays in a simple table format
static void printArray(const std::vector<Book>& arr, const char* label) {
    std::cout << "\n=== " << label << " ===\n";
    for (const auto& b : arr) {
        std::cout << b.getISBN() << " | "
            << b.getTitle() << " | "
            << (b.getAvailability() ? "Available" : "Borrowed")
            << "\n";
    }
}

int main() {
    using std::cout;

    // --- 1. Correct book initialisation ---
    cout << "=== Correct Book’s information ===\n";
    Book b1("Book A", "Author A", "111", "2024-01-01", true);
    Book b2("Book B", "Author B", "222", "2024-01-01", true);
    Book b3("Book C", "Author C", "333", "2024-01-01", false);

    b1.displayBookDetails();
    b2.displayBookDetails();
    b3.displayBookDetails();

    // --- 2. Incorrect book initialisation ---
    cout << "\n=== Incorrect Book’s information (expected failures) ===\n";
    try { Book bad1("", "Author X", "111", "2024-01-01"); }
    catch (const std::exception& e) { cout << "bad1 failed: " << e.what() << "\n"; }

    try { Book bad2("Title X", "", "222", "2024-01-01"); }
    catch (const std::exception& e) { cout << "bad2 failed: " << e.what() << "\n"; }

    try { Book bad3("Title Y", "Author Y", "XX", "2024-01-01"); } // invalid ISBN
    catch (const std::exception& e) { cout << "bad3 failed: " << e.what() << "\n"; }

    // --- 3. Arrays: Ascending, Descending, Mixed ---
    std::vector<Book> asc = {
        Book("A", "Auth", "111", "2024-01-01"),
        Book("B", "Auth", "222", "2024-01-01"),
        Book("C", "Auth", "333", "2024-01-01")
    };
    std::vector<Book> desc = {
        Book("C", "Auth", "333", "2024-01-01"),
        Book("B", "Auth", "222", "2024-01-01"),
        Book("A", "Auth", "111", "2024-01-01")
    };
    std::vector<Book> mixed = {
        Book("B", "Auth", "222", "2024-01-01"),
        Book("C", "Auth", "333", "2024-01-01"),
        Book("A", "Auth", "111", "2024-01-01")
    };

    printArray(asc, "Before sort (ASC input)");
    printArray(desc, "Before sort (DESC input)");
    printArray(mixed, "Before sort (MIXED input)");

    // --- 4. Call sort function on all arrays ---
    sortBooksByISBN(asc);
    sortBooksByISBN(desc);
    sortBooksByISBN(mixed);

    printArray(asc, "After sort (ASC input)");
    printArray(desc, "After sort (DESC input)");
    printArray(mixed, "After sort (MIXED input)");

    // --- 5. Borrow/Return test ---
    std::cout << "\n=== Borrow/Return test ===\n";
    std::cout << "Borrow b1: " << (b1.borrowBook() ? "OK" : "FAILED") << "\n";
    std::cout << "Borrow b1 again: " << (b1.borrowBook() ? "OK" : "FAILED (expected)") << "\n";
    b1.returnBook();
    std::cout << "Return b1 done.\n";

    return 0;
}
