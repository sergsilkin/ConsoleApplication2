#ifndef MANAGERDB_STUDENT_H
#define MANAGERDB_STUDENT_H

#include <iostream>
#include <string>
#include <utility>

class Student {
public:
    int id;

    std::string login;
    std::string password;

    std::string name;
    std::string surname;

    Student(int id,
            std::string login,
            std::string password,
            std::string name,
            std::string surname);
};


#endif //MANAGERDB_STUDENT_H
