
#pragma once
#include "util.h"
#include <string>

#include "Book.h"
#include "Person.h"

using namespace std;
struct BookNode {
    Book* book;
    BookNode* link;
};


struct PersonNode {
    Person *person;
    PersonNode* link;
};

enum BookType {
    BOOK_TYPE_CHILDREN,
    BOOK_TYPE_COMPUTER,
    BOOK_TYPE_NOVEL,
    BOOK_TYPE_ERROR
};

BookType getBookType(int code);
string getBookTypeString(int code);
PersonNode* getPerson(PersonNode* person[], int personId);
BookNode* searchBookByTitle(BookNode* library[], const string &title);
BookNode* searchBook(BookNode* library[], int code, const string& title);
//void rentBook(int id, const string& title);
void rentBook(PersonNode * person, BookNode *book);
void returnBook(int id, int code);
void showInformation(int id, const string& name);
void showBooks();
void initializeLibrary(BookNode* library[]);
void initializePeople(PersonNode* person[]);
void printLibrary(BookNode* library[]);
void printPeople(PersonNode *person[]);
