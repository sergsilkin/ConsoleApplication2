#include "Student.h"

Student::Student(int id, std::string login, std::string password, std::string name, std::string surname) {
    this->id = id;
    this->login = std::move(login);
    this->password = std::move(password);
    this->name = std::move(name);
    this->surname = std::move(surname);
}
