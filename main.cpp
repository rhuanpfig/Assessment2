#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;
    string dateAdded;

public:
    void setBookDetails(string t, string a, string i, string d, bool avail = true) {
        title = t;
        author = a;
        isbn = i;
        dateAdded = d;
        isAvailable = avail;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    string getISBN() {
        return isbn;
    }

    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully.\n";
            return true;
        } else {
            cout << "Sorry, book already borrowed.\n";
            return false;
        }
    }

    void returnBook() {
        isAvailable = true;
    }
};

int main() {
    Book books[5];
    books[0].setBookDetails("Book A", "Author A", "111", "01/01/2024");
    books[1].setBookDetails("Book B", "Author B", "222", "01/01/2024");
    books[2].setBookDetails("Book C", "Author C", "333", "01/01/2024");
    books[3].setBookDetails("Book D", "Author D", "444", "01/01/2024");
    books[4].setBookDetails("Book E", "Author E", "555", "01/01/2024");

    string inputISBN;
    while (true) {
        cout << "Enter ISBN to borrow (or 0 to quit): ";
        cin >> inputISBN;

        if (inputISBN == "0")
            break;

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                books[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    return 0;
}
