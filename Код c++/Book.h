#pragma once
#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int year;
    std::string isbn;

public:
    Book();
    Book(int id, const std::string& title, const std::string& author, int year, const std::string& isbn);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getIsbn() const;

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setYear(int year);
    void setIsbn(const std::string& isbn);

    std::string toCSV() const;
    static Book fromCSV(const std::string& line);
};