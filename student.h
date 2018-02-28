#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

struct Student{
        std::string vardas;
        std::string pavarde;
        int egzaminas;
        std::vector<int> nDarbas;
};

void addStudent(Student &, std::string, std::string, std::vector<int> &, int);
void printStudent(std::vector<Student> &);
void sortStudentByName(std::vector<Student> &);
void addStudentUI(Student &);
void readStudentsFromFile(std::vector<Student> &, std::string);
void createStudentFile(unsigned int, std::string);

#endif
