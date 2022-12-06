#pragma once

#include "Person.h"

class Student : protected Person {
public:
    Student(int id, const string &name, int count, const int code[])
            : Person(id, name, count) {
        for (int i = 0; i < count; ++i) {
            this->code[i] = code[i];
        }
    };

    void getCode(int studentCodes[]) {
        for (int i = 0; i < this->getCount(); ++i) {
            studentCodes[i] = this->code[i];
        }
    }

    void setCode(int bookCode) {
        if (this->getCount() <= 2) {
            this->code[this->getCount() - 1] = bookCode;
        } else {
            std::cout << "Student can't rent anymore books!" << std::endl;
        }
    }

    int getNumberOfBooksRented() const {
        return this->getCount();
    }

    Person &getParent() const {
        return (Person &) *this;
    }

private:
    int code[2]{};
};