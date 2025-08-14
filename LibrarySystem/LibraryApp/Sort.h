#pragma once
#include <vector>
#include "Book.h"

// Sorts books by ISBN in ascending order
void sortBooksByISBN(std::vector<Book>& books);

// Sorts books by ISBN in descending order
void sortBooksByISBNDesc(std::vector<Book>& books);

// Sorts books by title in ascending order (optional extra example)
void sortBooksByTitle(std::vector<Book>& books);
