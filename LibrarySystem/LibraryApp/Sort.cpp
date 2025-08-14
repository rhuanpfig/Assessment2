#include "Sort.h"
#include <algorithm>

// Sort by ISBN (ascending)
void sortBooksByISBN(std::vector<Book>& books) {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.getISBN() < b.getISBN();
        });
}

// Sort by ISBN (descending)
void sortBooksByISBNDesc(std::vector<Book>& books) {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.getISBN() > b.getISBN();
        });
}


// Sort by title (ascending)
void sortBooksByTitle(std::vector<Book>& books) {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.getTitle() < b.getTitle();
        });
}
