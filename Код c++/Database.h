#pragma once
#include "Book.h"
#include <vector>
#include <string>

class Database {
private:
    std::string filename;

public:
    Database(const std::string& filename);
    void save(const std::vector<Book>& books) const;
    std::vector<Book> load() const;
};