#include "Book.h"
#include <sstream>

Book::Book() : id(0), year(0) {}

Book::Book(int id, const std::string& title, const std::string& author, int year, const std::string& isbn)
    : id(id), title(title), author(author), year(year), isbn(isbn) {
}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
std::string Book::getIsbn() const { return isbn; }

void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setYear(int y) { year = y; }
void Book::setIsbn(const std::string& i) { isbn = i; }

std::string Book::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << title << "," << author << "," << year << "," << isbn;
    return oss.str();
}

Book Book::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string part;
    int id, year;
    std::string title, author, isbn;

    std::getline(ss, part, ','); id = std::stoi(part);
    std::getline(ss, title, ',');
    std::getline(ss, author, ',');
    std::getline(ss, part, ','); year = std::stoi(part);
    std::getline(ss, isbn, ',');

    return Book(id, title, author, year, isbn);
}