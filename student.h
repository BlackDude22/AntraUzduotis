#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "antra_math.h"

struct Student{
        std::string vardas;
        std::string pavarde;
        int egzaminas;
        std::vector<int> nDarbas;
        double average;
        double median;
};

void addStudentUI(std::vector<Student> &);
void createStudentFile(unsigned int, std::string);
bool customCompare(Student &, Student &);

template <typename T> void addStudent(T &stud, std::string name, std::string lastName, std::vector<int> marks, int exam){
    if (name.empty())
        throw "Neivestas vardas";
    else if (lastName.empty())
        throw "Neivesta pavarde";
    else if (marks.size() == 0)
        throw "Neivestas ne vienas pazymys";
    else {
        Student student;
        student.vardas = name;
        student.pavarde = lastName;
        student.nDarbas = marks;
        student.egzaminas = exam;
        student.average = average(marks);
        student.median = median(marks);
        stud.push_back(student);
    }
}

template <typename T> void printStudent(T &stud){
    const int width = 20, prec = 2;
    sortContainer(stud);
    std::cout << std::setw(width) << "Pavarde" << std::setw(width) <<  "Vardas"
    << std::setw(width) << "Galutinis-vidurkis" << std::setw(width) << "Galutinis-mediana" << std::endl;
    //isvardijami visi vectoriuje stud saugomi studentai
    for (const auto& i: stud)
        std::cout << std::setw(width) << i.pavarde << std::setw(width) << i.vardas
        << std::setw(width) << std::fixed << std::setprecision(prec) << i.average*0.4+i.egzaminas*0.6 
        << std::setw(width) << std::fixed << std::setprecision(prec) << i.median*0.4+i.egzaminas*0.6 << std::endl;
}
template <typename T> void readStudentsFromFile(T &stud, std::string fileName){
    std::ifstream inf;
    inf.exceptions ( std::ifstream::failbit);
    try{
        inf.open(fileName);
        std::string singleLine;
        //failas nuskaitomas po viena eilute
        while (getline(inf, singleLine)){
            std::vector<std::string> words;
            std::istringstream ss(singleLine);
            std::string temp;
            //gauta eilute skaidoma i zodzius
            while (ss >> temp)
                words.push_back(temp);
            //minimalus zodziu skaicius kad irasas butu galimas 4
            if (words.size() > 3) {
                std::string name = words[1], lastName = words[0];
                std::vector<int> marks;
                for (unsigned int i = 2; i < words.size()-1; i++)
                    marks.push_back(std::stoi(words[i]));
                int exam = std::stoi(words[words.size()-1]);
                try {
                    addStudent(stud, name, lastName, marks, exam);
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }
            }
        }
        inf.close();
    } catch (std::exception& e){
        // sitas labai letina programos darba
        if (!inf.eof())
            std::cout << "Failed to read from " + fileName << std::endl;
        inf.clear();
    }
}
template <typename T> void sortContainer(T &);

#endif
