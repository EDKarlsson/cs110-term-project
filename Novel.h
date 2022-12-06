#pragma once
#include "Book.h"

using namespace std;

class Novel : public Book {
public:
    Novel(int code, const string& title, int available, int rented, int bookDate)
            : Book(code, title, available, rented), publish_date(bookDate) {};
    int getPublishDate() const {
        return this->publish_date;
    }
private:
    int publish_date;
};