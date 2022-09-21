#include <iostream>
using namespace  std;

class Person {
private:
    string name;
public:
    virtual void printName () const {cout << name<<" ";}
    Person(string name) : name(name) {}
};

class Student: public Person{
private:
    string id;
public:
    Student(string id, string name):id(id), Person(name){printName();}
    void printName() const {
        cout << id << " ";
        Person::printName();
    }
};

void Print(Person& p) {p.printName();}

int main() {
    Student s("101", "Tommy");
    Print(s);
    return 0;
}



