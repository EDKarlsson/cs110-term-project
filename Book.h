#pragma once

#include <string>

using namespace std;

class Book {
public:
    Book(const int bookCode, const string &bookTitle, const int bookAvailable, const int bookRented)
            : code(bookCode), title(bookTitle), available(bookAvailable), rented(bookRented) {};

    string getBookTitle() const {
        return this->title;
    }

    int getCode() const {
        return this->code;
    }

    int getAvailable() const {
        return this->available;
    }

    int getRented() const {
        return this->rented;
    }

    void decreaseAvailable() {
        this->available--;
    }

    void increaseAvailable() {
        this->available++;
    }

private:
    int code;
    string title;
    int available;
    int rented;

};