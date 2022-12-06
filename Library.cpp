#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "Book.h"
#include "ChildrenBook.h"
#include "ComputerBook.h"
#include "Teacher.h"
#include "Student.h"
#include "Person.h"
#include "Novel.h"
#include "Library.h"

/**
 * Utility function that converts an integer code into an enum.
 *
 * @param code
 * @return
 */
BookType getBookType(int code) {
    if (code >= 1000 and code < 2000) {
        return BOOK_TYPE_CHILDREN;
    } else if (code >= 2000 and code < 3000) {
        return BOOK_TYPE_COMPUTER;
    } else if (code > 3000 && code <= 4000) {
        return BOOK_TYPE_NOVEL;
    }
    return BOOK_TYPE_ERROR;
}

/**
 * Utility function that converts an integer code into a string.
 *
 * @param code
 * @return
 */
string getBookTypeString(int code) {
    if (code >= 1000 and code < 2000) {
        return "children";
    } else if (code >= 2000 and code < 3000) {
        return "computer";
    } else if (code > 3000 && code <= 4000) {
        return "novel";
    }
    return "MENU_ERROR";
}
BookNode* searchBookByTitle(BookNode* library[], const string &title){
    BookNode *tmpNode = library[0];
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        tmpNode = library[i];
        while(!found && tmpNode != nullptr){
            if(tmpNode->book->getBookTitle() == title) {
                found = true;
            } else {
                tmpNode = tmpNode->link;
            }
        }
        if(found) break;
    }
    return tmpNode;
}
/**
 * Searches the library list using a book code and the name of the book.
 *
 * @param library
 * @param code
 * @param title
 * @return
 */
BookNode *searchBook(BookNode *library[], int code, const string &title) {
    BookNode *tmpNode = nullptr;
    bool wrongCode = false;
    if (code >= 1000 and code < 2000) {
        tmpNode = library[0];
    } else if (code >= 2000 and code < 3000) {
        tmpNode = library[1];
    } else if (code > 3000 && code <= 4000) {
        tmpNode = library[2];
    } else if (code < 1000 or code > 4000) {
        std::cout << "No such code!" << std::endl;
        wrongCode = true;
    }
    while (!wrongCode && tmpNode != nullptr) {
        if (title == tmpNode->book->getBookTitle()) {
            if (tmpNode->book->getCode() != code) {
                std::cout << "Code and title do not match" << std::endl;
            } else {
                return tmpNode;
            }
        }
        tmpNode = tmpNode->link;
    }
    return tmpNode;
}

PersonNode *getPerson(PersonNode *person[], int personId) {
    PersonNode *tmpPerson = nullptr;
    if (personId <= 100) {
        tmpPerson = person[0];
        while (tmpPerson != nullptr) {
            if (tmpPerson->person->getId() == personId) {
                return tmpPerson;
            }
            tmpPerson = tmpPerson->link;
        }
    } else {
        tmpPerson = person[1];
        while (tmpPerson != nullptr) {
            if (tmpPerson->person->getId() == personId) {
                return tmpPerson;
            }
            tmpPerson = tmpPerson->link;
        }
    }
    return tmpPerson;
}

void rentBook(PersonNode *person, BookNode *bookNode) {
    bool canRent = false;
    if (bookNode->book->getAvailable() > 0) {
        if (person->person->getId() <= 100) {
            // Teacher
            Teacher *teacher = (Teacher *) person->person;
            if (teacher->getNumberOfBooksRented() <= 3) {
                teacher->setCode(bookNode->book->getCode());
                canRent = true;
            }
        } else {
            // Student
            Student *student = (Student *) person->person;
            if (student->getNumberOfBooksRented() <= 2) {
                student->setCode(bookNode->book->getCode());
                canRent = true;
            }
        }
        if (canRent) {
            bookNode->book->decreaseAvailable();
        }
    } else {
        std::cout << "Book is not available to rent." << std::endl;
    }
}

void returnBook(int id, int code) {

}

void showInformation(int id, const string &name) {

}

void showBooks(BookNode *library[]) {
    std::cout << std::setfill('=');

}

/**
 * Initializes the List of people that belong to the library. The data is read in from a text file.
 *
 * @param person
 */
void initializePeople(PersonNode *person[]) {
    // TODO: Change this back to "book.txt"
    ifstream personFile("/home/dank/git/wyzant/brandon.l/cs-110-term-project/person.txt");
    string line;
    while (getline(personFile, line)) {
        istringstream iss(line);
        int id;
        int numberRented;
        string name;
        int rentedBooksCode[3];
        Teacher *teacher;
        Student *student;

        PersonNode *personNode = new PersonNode();
        personNode->link = nullptr;

        if (!(iss >> id >> name >> numberRented)) {
            cout << "Error, unable to read person!";
            exit(true);
        }
        if (id <= 100) {
            // teacher
            iss >> rentedBooksCode[0] >> rentedBooksCode[1] >> rentedBooksCode[2];
            teacher = new Teacher(id, name, numberRented, rentedBooksCode);
            personNode->person = &(teacher->getParent());
            // Insert into linked list
            personNode->link = person[0];
            person[0] = personNode;
        } else if (id > 100) {
            // student
            iss >> rentedBooksCode[0] >> rentedBooksCode[1] >> rentedBooksCode[2];
            student = new Student(id, name, numberRented, rentedBooksCode);
            personNode->person = &(student->getParent());
            // Insert into linked list
            personNode->link = person[1];
            person[1] = personNode;
            continue;
        } else {
            cout << "Invalid code";
            exit(true);
        }
    }
}

/**
 * Initializes the library of books. The data is read in from a text file.
 * @param library
 */
void initializeLibrary(BookNode *library[]) {
    // TODO: Change this back to "book.txt"
    ifstream bookFile("/home/dank/git/wyzant/brandon.l/cs-110-term-project/book.txt");
    string line;
    while (getline(bookFile, line)) {
        istringstream iss(line);
        int code;
        string title;
        int year;
        int available;
        int rented;
        string publisher;
        int age;

        BookNode *newBookNode = new BookNode();
        newBookNode->link = nullptr;
        if (!(iss >> code >> title)) {
            cout << "Error, unable to read book code!";
            exit(true);
        }
        if (code > 1000 && code <= 2000) {
            if (!(iss >> age >> available >> rented)) {
                exit(true);
            }
            newBookNode->book = new ChildrenBook(code, title, available, rented, age);
            // Insert into linked list
            newBookNode->link = library[0];
            library[0] = newBookNode;
        } else if (code > 2000 && code <= 3000) {
            if (!(iss >> publisher >> available >> rented)) {
                exit(true);
            }
            newBookNode->book = new ComputerBook(code, title, available, rented, publisher);
            // Insert into linked list
            newBookNode->link = library[1];
            library[1] = newBookNode;
        } else if (code > 3000 && code <= 4000) {
            if (!(iss >> year >> available >> rented)) {
                exit(true);
            }
            newBookNode->book = new Novel(code, title, available, rented, year);
            // Insert into linked list
            newBookNode->link = library[2];
            library[2] = newBookNode;
        } else {
            cout << "Invalid code";
            exit(true);
        }

    }
}

/**
 * Print statement for debugging the library in the application
 * @param library
 */
void printLibrary(BookNode *library[]) {
    BookNode *tmpNode;
    tmpNode = library[0];
    std::cout << "Printing books" << std::endl;
    while (tmpNode != nullptr) {
        std::cout << "Book " << tmpNode->book->getBookTitle() << ", available: " << tmpNode->book->getAvailable()
                  << std::endl;
        tmpNode = tmpNode->link;
    }

    tmpNode = library[1];
    while (tmpNode != nullptr) {
        std::cout << "Book " << tmpNode->book->getBookTitle() << ", available: " << tmpNode->book->getAvailable()
                  << std::endl;
        tmpNode = tmpNode->link;
    }
    tmpNode = library[2];
    while (tmpNode != nullptr) {
        std::cout << "Book " << tmpNode->book->getBookTitle() << ", available: " << tmpNode->book->getAvailable()
                  << std::endl;
        tmpNode = tmpNode->link;
    }
}

/**
 * Print statement used for debugging the person list in the application
 * @param person
 */
void printPeople(PersonNode *person[]) {
    PersonNode *tmpNode;
    tmpNode = person[0];
    Teacher *teacher;
    Student *student;
    int bookCodes[3];
    std::cout << "Printing people" << std::endl;
    while (tmpNode != nullptr) {
        teacher = (Teacher *) tmpNode->person;
        std::cout << "Teacher id: " << teacher->getParent().getId() << ", name: " << teacher->getParent().getName()
                  << ", rented books: " << teacher->getParent().getCount();
        teacher->getCode(bookCodes);
        std::cout << ", Book Codes: ";
        for (int i = 0; i < teacher->getParent().getCount(); ++i) {
            std::cout << bookCodes[i] << " ";
        }
        std::cout << std::endl;
        tmpNode = tmpNode->link;
    }

    tmpNode = person[1];
    while (tmpNode != nullptr) {
        student = (Student *) tmpNode->person;
        std::cout << "Student id: " << student->getParent().getId() << ", name: " << student->getParent().getName()
                  << ", rented books: " << student->getParent().getCount();
        student->getCode(bookCodes);
        std::cout << ", Book Codes: ";
        for (int i = 0; i < student->getParent().getCount(); ++i) {
            std::cout << bookCodes[i] << " ";
        }
        std::cout << std::endl;
        tmpNode = tmpNode->link;
    }
}
