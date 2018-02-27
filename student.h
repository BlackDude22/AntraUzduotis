#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>
#include <vector>
#include <string>

struct Student{
        std::string vardas;
        std::string pavarde;
        std::vector<int> nDarbas;
        int egzaminas;
};

void addStudent(Student &);
void printStudent(Student &);
void printStudentInfo();
void generateMarks(std::vector<int> &);
void generateRandomMarks(std::vector<int> &);
void readStudentsFromFile(std::vector<Student> &, std::string);
void createStudentFile(int, std::string);

#endif