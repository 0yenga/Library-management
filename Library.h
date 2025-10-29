#pragma once
#include "Book.h"
#include "Database.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;
    Database db;
    int nextId;

public:
    Library(const std::string& filename);

    void addBook();
    void removeBook();
    void showBooks() const;
    void findBook() const;
    void saveData() const;
};