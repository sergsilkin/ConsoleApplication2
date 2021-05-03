#ifndef MANAGERDB_TEACHER_H
#define MANAGERDB_TEACHER_H

#include <iostream>
#include <string>
#include <utility>

class Teacher {
public:
    int id;

    std::string login;
    std::string password;

    std::string name;
    std::string surname;

    Teacher(int id,
            std::string login,
            std::string password,
            std::string name,
            std::string surname);
};

#endif //MANAGERDB_TEACHER_H
