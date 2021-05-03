#ifndef MANAGERDB_MANAGERDB_H
#define MANAGERDB_MANAGERDB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "Student.h"
#include "Teacher.h"


class ManagerDb {
private:
    static ManagerDb *managerDb_;

    ManagerDb();

    std::map<std::string, std::string> tables;

    void addTable(const std::string &newTable, const std::string &filePath);

    std::vector<Student> _students;
    std::vector<Teacher> _teachers;

    void reloadStudents();
    void reloadTeachers();

    bool tableExist(const std::string &table);


public:
    ManagerDb(ManagerDb &other) = delete;

    void operator=(const ManagerDb &) = delete;

    /*
     * Returns a pointer to a database.
     *
     * Implements singleton pattern.
     */
    static ManagerDb *GetInstance();

    /*
     * Inits all tables.
    */
    void launchDatabase();

    //TITLE Tables work:

    /*
    Clears data in all tables.
    */
    void clearAllTables();

    /*
     * Clear data in specific table.
     */
    void clearTable(const std::string &clearingTable);


    //TITLE Students work:

    /*
     * Retrieves all students.
     */
    std::vector<Student> getAllStudents();

    /*
     * Retrieves students store in cache represented by private variable.
     *
     * @return this->_students
     */
    std::vector<Student> getStudentsCached();

    /*
     * Updates students stored in cache.
     */
    void refreshStudents();

    /*
     * Add a student to the database.
     *
     * Note that this method adds the new student to the database set which is represented as a local variable,
     * but DOES NOT save it to the files.
     *
     * NOTE: To save added data run saveChangesStudents()
     */
    void addStudent(const std::string &login, const std::string &password, const std::string &name,
                    const std::string &surname);


    //TITLE Teachers work:

    /*
     * Retrieves all teachers.
     */
    std::vector<Teacher> getAllTeachers();

    /*
     * Retrieves teachers store in cache represented by private variable.
     *
     * @return this->_teachers
     */
    std::vector<Teacher> getTeachersCached();

    /*
     * Updates teachers stored in cache.
     */
    void refreshTeachers();

    /*
     * Add a teacher to the database.
     *
     * Note that this method adds the new teacher to the database set which is represented as a local variable,
     * but DOES NOT save it to the files.
     *
     * NOTE: To save added data run saveChangesTeachers()
     */
    void addTeacher(const std::string &login, const std::string &password, const std::string &name,
                    const std::string &surname);



    //TITLE Changes handlers:

    /*
     * Saves all cached data to files.
     */
    void saveAllChanges();

    /*
     * Saves cached students to file.
     */
    void saveChangesStudents();

    /*
     * Saves cached teachers to file.
     */
    void saveChangesTeachers();

    /*
     * Saves cached marks to file.
     */
    void saveChangesMarks();


    //TITLE Authentication:

    /*
     * Authenticate student by login and password.
     *
     * @param login - string with login information.
     * @param password - string with password information.
     *
     * @return studentId - gets student's id if authentication is successful.
     * Otherwise, returns -1
     */
    int authenticateStudent(const std::string &login, const std::string &password);

    /*
     * Authenticate teacher by login and password.
     *
     * @param login - string with login information.
     * @param password - string with password information.
     *
     * @return studentId - gets teacher's id if authentication is successful.
     * Otherwise, returns -1
     */
    int authenticateTeacher(const std::string &login, const std::string &password);

};


#endif //MANAGERDB_MANAGERDB_H

#pragma clang diagnostic pop