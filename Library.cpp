#include "Library.h"
#include <iostream>

Library::Library(const std::string& filename) : db(filename), nextId(1) {
    books = db.load();
    if (!books.empty())
        nextId = books.back().getId() + 1;
}

void Library::addBook() {
    std::string title, author, isbn;
    int year;
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Year: ";
    std::cin >> year;
    std::cin.ignore();
    std::cout << "ISBN: ";
    std::getline(std::cin, isbn);

    books.emplace_back(nextId++, title, author, year, isbn);
    std::cout << "Book added successfully!\n";
}

void Library::removeBook() {
    int id;
    std::cout << "Enter the ID of the book to remove: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            books.erase(it);
            std::cout << "Book removed.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::showBooks() const {
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }
    for (const auto& b : books) {
        std::cout << b.getId() << " | " << b.getTitle() << " | "
            << b.getAuthor() << " | " << b.getYear() << " | "
            << b.getIsbn() << "\n";
    }
}

void Library::findBook() const {
    std::string keyword;
    std::cout << "Enter a keyword (title or author): ";
    std::getline(std::cin, keyword);

    bool found = false;
    for (const auto& b : books) {
        if (b.getTitle().find(keyword) != std::string::npos ||
            b.getAuthor().find(keyword) != std::string::npos)
        {
            std::cout << b.getId() << " | " << b.getTitle() << " | "
                << b.getAuthor() << " | " << b.getYear() << " | "
                << b.getIsbn() << "\n";
            found = true;
        }
    }
    if (!found)
        std::cout << "No matching books found.\n";
}

void Library::saveData() const {
    db.save(books);
    std::cout << "Data saved to file.\n";
}