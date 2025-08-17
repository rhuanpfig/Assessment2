#include "student.h"   // puxa Book.h e Sort.h
#include <iostream>
using namespace std;

void runSimpleTests() {
    cout << "\n=== Running Simple Test Cases ===\n";

    // ✅ Válido (ordem correta: title, author, isbn, date, availability)
    cout << "\n[TEST 1] Valid book\n";
    Book b1("C++ Basics", "John Smith", "1001", "2023-01-01", true);
    b1.displayBookDetails();

    // ❌ ISBN inválido
    cout << "\n[TEST 2] Invalid ISBN\n";
    try {
        Book badIsbn("Data Structures", "Jane Doe", "XX", "2023-05-10", false);
    }
    catch (const std::exception& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // ❌ Campos vazios
    cout << "\n[TEST 3] Empty fields\n";
    try {
        Book empty("", "", "1002", "", false);
    }
    catch (const std::exception& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // ✅ Outro válido
    cout << "\n[TEST 4] Another valid book\n";
    Book b2("Algorithms", "Alan Turing", "1003", "2024-03-15", true);
    b2.displayBookDetails();

    cout << "\n=== Tests Completed ===\n";
}
