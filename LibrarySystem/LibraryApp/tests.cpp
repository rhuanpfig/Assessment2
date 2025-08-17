#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Running Test Cases for Student Class ===" << endl;

    // ✅ Test case 1: Valid book data
    cout << "\n[TEST 1] Valid Book Data" << endl;
    Student validBook("C++ Basics", "John Smith", 12345, true, "2023-01-01");
    validBook.display();

    // ❌ Test case 2: Invalid ISBN (negative number)
    cout << "\n[TEST 2] Invalid ISBN" << endl;
    Student invalidISBN("Data Structures", "Jane Doe", -999, false, "2023-05-10");
    invalidISBN.display();

    // ❌ Test case 3: Empty fields
    cout << "\n[TEST 3] Empty Fields" << endl;
    Student emptyBook("", "", 0, false, "");
    emptyBook.display();

    // ✅ Test case 4: Another valid entry
    cout << "\n[TEST 4] Another Valid Book" << endl;
    Student anotherBook("Algorithms", "Alan Turing", 67890, true, "2024-03-15");
    anotherBook.display();

    cout << "\n=== Test Cases Completed ===" << endl;
    return 0;
}
