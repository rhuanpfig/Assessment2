#include <iostream>
#include <vector>
#include "student.h"

// Print helper
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

    // 1) Valid book initialization
    cout << "=== Correct Book’s information ===\n";
    Book b1("The C Programming Language", "Kernighan & Ritchie", "9780131103627", "2024-01-01", true);
    Book b2("Introduction to Algorithms", "Cormen et al.", "9780262033848", "2024-01-01", true);
    Book b3("Design Patterns", "Gamma et al.", "9780201633610", "2024-01-01", false);

    b1.displayBookDetails();
    b2.displayBookDetails();
    b3.displayBookDetails();

    // 2) Invalid book initialization (expected failures)
    cout << "\n=== Incorrect Book’s information (expected failures) ===\n";
    try { Book bad1("", "Author X", "9780131103627", "2024-01-01"); }
    catch (const std::exception& e) { cout << "bad1 failed: " << e.what() << "\n"; }

    try { Book bad2("Some Title", "", "9780262033848", "2024-01-01"); }
    catch (const std::exception& e) { cout << "bad2 failed: " << e.what() << "\n"; }

    try { Book bad3("Another Title", "Author Y", "XX", "2024-01-01"); } // invalid ISBN
    catch (const std::exception& e) { cout << "bad3 failed: " << e.what() << "\n"; }

    // 3) Arrays for sorting (ASC/DESC/MIXED by ISBN)
    // Note: ASC input is already in ascending ISBN order
    std::vector<Book> asc = {
        Book("The C Programming Language", "Kernighan & Ritchie", "9780131103627", "2024-01-01"),
        Book("Design Patterns", "Gamma et al.", "9780201633610", "2024-01-01"),
        Book("Introduction to Algorithms", "Cormen et al.", "9780262033848", "2024-01-01")
    };

    // DESC input is descending ISBN order
    std::vector<Book> desc = {
        Book("Introduction to Algorithms", "Cormen et al.", "9780262033848", "2024-01-01"),
        Book("Design Patterns", "Gamma et al.", "9780201633610", "2024-01-01"),
        Book("The C Programming Language", "Kernighan & Ritchie", "9780131103627", "2024-01-01")
    };

    // MIXED input is a shuffled order
    std::vector<Book> mixed = {
        Book("Design Patterns", "Gamma et al.", "9780201633610", "2024-01-01"),
        Book("Introduction to Algorithms", "Cormen et al.", "9780262033848", "2024-01-01"),
        Book("The C Programming Language", "Kernighan & Ritchie", "9780131103627", "2024-01-01")
    };

    printArray(asc, "Before sort (ASC input)");
    printArray(desc, "Before sort (DESC input)");
    printArray(mixed, "Before sort (MIXED input)");

    // 4) Call sort functions
    sortBooksByISBN(asc);          // ascending
    sortBooksByISBNDesc(desc);     // descending
    sortBooksByISBN(mixed);        // ascending

    printArray(asc, "After sort (ASC input)");
    printArray(desc, "After sort (DESC input)");
    printArray(mixed, "After sort (MIXED input)");

    // 5) Borrow/Return test
    std::cout << "\n=== Borrow/Return test ===\n";
    std::cout << "Borrow b1: " << (b1.borrowBook() ? "OK" : "FAILED") << "\n";
    std::cout << "Borrow b1 again: " << (b1.borrowBook() ? "OK" : "FAILED (expected)") << "\n";
    b1.returnBook();
    std::cout << "Return b1 done.\n";

    return 0;
}
