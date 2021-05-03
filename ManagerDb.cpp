#include "ManagerDb.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
ManagerDb *ManagerDb::managerDb_ = nullptr;

ManagerDb::ManagerDb() {
    addTable("students", "students.txt");
    addTable("teachers", "teachers.txt");
    addTable("marks", "marks.txt");
}

ManagerDb *ManagerDb::GetInstance() {
    if (managerDb_ == nullptr) {
        managerDb_ = new ManagerDb();
    }

    return managerDb_;
}

void ManagerDb::launchDatabase() {
    std::fstream appendFileToWorkWith;
    for (auto &[table, path] : tables) {
        appendFileToWorkWith.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

        // If file does not exist, Create new file
        if (!appendFileToWorkWith) {
            std::cout << "Cannot open file, file does not exist. Creating new file..";

            appendFileToWorkWith.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc);
            appendFileToWorkWith << "\n";
        } else {    // use existing file
            std::cout << "Success! " << table << " was found. \n";
            std::cout << "\n";
        }
        appendFileToWorkWith.close();
    }
}

void ManagerDb::addTable(const std::string &newTable, const std::string &filePath) {
    tables.insert({newTable, filePath});
}

void ManagerDb::clearAllTables() {
    std::fstream clearer;
    std::fstream checker;

    for (const auto &[table, path] : tables) {
        checker.open(path);

        if (!checker.good()) {
            std::cout << "Cannot open file, file does not exist: " << path << std::endl;
        } else {
            std::cout << "\n\tSuccess! " << table << " was cleared. \n";
            clearer.open(path, std::fstream::out | std::fstream::trunc);
            clearer.close();
            std::cout << "\n";
        }

        checker.close();
    }
}

void ManagerDb::clearTable(const std::string &clearingTable) {
    std::fstream clearer;
    std::fstream checker;

    try {
        checker.open(tables.at(clearingTable));

        if (!checker.good()) {
            std::cout << "Cannot open file, file does not exist: " << clearingTable;
        } else {
            std::cout << "\n\tSuccess! " << clearingTable << " was cleared. \n";
            clearer.open(clearingTable, std::fstream::out | std::fstream::trunc);
            std::cout << "\n";
        }

        clearer.close();
    } catch (std::out_of_range) {
        std::cout << "There is no such table: " << clearingTable << std::endl;
    }
}


void ManagerDb::reloadStudents() {

    if (tableExist("students")) {
        _students.clear();
        std::ifstream readFile(tables.at("students"));

        int id;
        std::string login, password, name, surname;
        while (readFile >> id >> login >> password >> name >> surname) {
            auto *temp = new Student(id, login, password, name, surname);
            _students.emplace_back(*temp);
            delete temp;
        }
    } else {
        std::cout << "\n\nERROR! Table 'students' does not exist!\n";
        std::cout << "\tPlease, run: ManagerDb::launchDatabase\n\n";
    }
}

void ManagerDb::reloadTeachers() {

    if (tableExist("teachers")) {
        _teachers.clear();
        std::ifstream readFile(tables.at("teachers"));

        int id;
        std::string login, password, name, surname;
        while (readFile >> id >> login >> password >> name >> surname) {
            auto *temp = new Teacher(id, login, password, name, surname);
            _teachers.emplace_back(*temp);
            delete temp;
        }
    } else {
        std::cout << "\n\nERROR! Table 'teachers' does not exist!\n";
        std::cout << "\tPlease, run: ManagerDb::launchDatabase\n\n";
    }
}

void ManagerDb::refreshStudents() {
    reloadStudents();
}

void ManagerDb::refreshTeachers() {
    reloadTeachers();
}

std::vector<Student> ManagerDb::getAllStudents() {
    reloadStudents();

    return _students;
}

std::vector<Teacher> ManagerDb::getAllTeachers() {
    reloadTeachers();

    return _teachers;
}

std::vector<Student> ManagerDb::getStudentsCached() {
    return _students;
}

std::vector<Teacher> ManagerDb::getTeachersCached() {
    return _teachers;
}

void ManagerDb::addStudent(const std::string &login, const std::string &password, const std::string &name,
                           const std::string &surname) {
    reloadStudents();

    int newStudentId;

    if (!_students.empty())
        newStudentId = _students.back().id + 1;
    else
        newStudentId = 1;

    auto *newStudent = new Student(newStudentId, login, password, name, surname);

    _students.emplace_back(*newStudent);

    delete newStudent;
}

void ManagerDb::addTeacher(const std::string &login, const std::string &password, const std::string &name,
                           const std::string &surname) {
    reloadTeachers();

    int newTeacherId;

    if (!_teachers.empty())
        newTeacherId = _teachers.back().id + 1;
    else
        newTeacherId = 1;

    auto *newTeacher = new Teacher(newTeacherId, login, password, name, surname);

    _teachers.emplace_back(*newTeacher);

    delete newTeacher;
}


void ManagerDb::saveAllChanges() {
    saveChangesStudents();
    saveChangesTeachers();
}

bool ManagerDb::tableExist(const std::string &table) {
    std::fstream checker(tables.at(table));

    return checker.good();
}

void ManagerDb::saveChangesStudents() {
    if (tableExist("students")) {
        std::fstream inputStudents;
        inputStudents.open(tables.at("students"), std::fstream::out | std::fstream::trunc);

        for (auto &student : _students) {
            inputStudents << student.id << ' ';
            inputStudents << student.login << ' ';
            inputStudents << student.password << ' ';
            inputStudents << student.name << ' ';
            inputStudents << student.surname;
            inputStudents << '\n';
        }
        std::cout << "\n\n\tStudents were successfully saved.\n\n";
    } else {
        std::cout << "\n\nERROR! Table 'students' does not exist!\n";
        std::cout << "\tPlease, run: ManagerDb::launchDatabase\n\n";
    }
}

void ManagerDb::saveChangesTeachers() {
    if (tableExist("teachers")) {
        std::fstream inputStudents;
        inputStudents.open(tables.at("teachers"), std::fstream::out | std::fstream::trunc);

        for (auto &teacher : _teachers) {
            inputStudents << teacher.id << ' ';
            inputStudents << teacher.login << ' ';
            inputStudents << teacher.password << ' ';
            inputStudents << teacher.name << ' ';
            inputStudents << teacher.surname;
            inputStudents << '\n';
        }
        std::cout << "\n\n\tTeachers were successfully saved.\n\n";
    } else {
        std::cout << "\n\nERROR! Table 'students' does not exist!\n";
        std::cout << "\tPlease, run: ManagerDb::launchDatabase\n\n";
    }
}

void ManagerDb::saveChangesMarks() {}


int ManagerDb::authenticateStudent(const std::string &login, const std::string &password) {

    int authStudentId = -1;

    reloadStudents();

    for (auto &student: _students) {
        if (login == student.login && password == student.password) {
            authStudentId = student.id;
        }
    }

    return authStudentId;
}

int ManagerDb::authenticateTeacher(const std::string &login, const std::string &password) {

    int authTeacherId = -1;

    reloadTeachers();

    for (auto &teacher: _teachers) {
        if (login == teacher.login && password == teacher.password) {
            authTeacherId = teacher.id;
        }
    }

    return authTeacherId;
}


#pragma clang diagnostic pop