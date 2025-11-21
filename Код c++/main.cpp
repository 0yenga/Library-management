#include "Library.h"
#include <iostream>

int main() {
    Library library("data.csv");

    while (true) {
        std::cout << "\n=== Library Menu ===\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Remove a book\n";
        std::cout << "3. Show all books\n";
        std::cout << "4. Find a book\n";
        std::cout << "5. Save and exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: library.addBook(); break;
        case 2: library.removeBook(); break;
        case 3: library.showBooks(); break;
        case 4: library.findBook(); break;
        case 5: library.saveData(); return 0;
        default: std::cout << "Invalid choice.\n"; break;
        }
    }
}