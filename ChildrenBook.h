#pragma once
#include "Book.h"
class ChildrenBook : public Book {
public:
    ChildrenBook(int code, const string& title, int available, int rented, int bookAge)
            : Book(code, title, available, rented), age(bookAge) {};
    int getAge() const {
        return this->age;
    }
private:
    int age;
};