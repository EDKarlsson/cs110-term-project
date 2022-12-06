#pragma once

#include <string>

using namespace std;

class Person {
public:
    Person(int id, const string &name, int count) : id(id), name(name), count(count) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getCount() const {
        return count;
    }

private:
    int id;
    string name;
    int count;
};