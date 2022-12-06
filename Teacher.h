#pragma once

#include "Person.h"

class Teacher : protected Person {
public:
    Teacher(int id, const string &name, int count, const int code[])
            : Person(id, name, count) {
        for (int i = 0; i < count; ++i) {
            this->code[i] = code[i];
        }
    };

    void getCode(int teacherCodes[]) {
        for (int i = 0; i < this->getCount(); ++i) {
            teacherCodes[i] = this->code[i];
        }
    }

    void setCode(int bookCode) {
        if (this->getCount() <= 3) {
            this->code[this->getCount() - 1] = bookCode;
        } else {
            std::cout << "Teacher can't rent anymore books!" << std::endl;
        }
    }

    int getNumberOfBooksRented() const {
        return this->getCount();
    }

    Person &getParent() const {
        return (Person &) *this;
    }

private:
    int code[3]{};
};