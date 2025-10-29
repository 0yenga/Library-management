#include "Database.h"
#include <fstream>
#include <iostream>

Database::Database(const std::string& filename) : filename(filename) {}

void Database::save(const std::vector<Book>& books) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file for writing." << std::endl;
        return;
    }
    for (const auto& b : books)
        file << b.toCSV() << "\n";
    file.close();
}

std::vector<Book> Database::load() const {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) return books;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty())
            books.push_back(Book::fromCSV(line));
    }
    file.close();
    return books;
}