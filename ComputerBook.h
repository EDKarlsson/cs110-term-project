#pragma once
#include "Book.h"

class ComputerBook : public Book {
public:
    ComputerBook(int code, const string& title, int available, int rented, const string& bookPublisher)
            : Book(code, title, available, rented), publisher(bookPublisher) {};
    string getPublisher() {
        return this->publisher;
    }
private:
    string publisher;
};