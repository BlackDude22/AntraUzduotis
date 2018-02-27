
#include <array>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "antra_math.h"
#include "student.h"

void printStudent2(std::vector<Student> &);
double average2(std::vector<int> &);


int main() {
    std::vector<Student> stud;
    std::vector<Student> goodStud;
    std::vector<Student> badStud;
    readStudentsFromFile(stud, "file1.txt");
    //printStudentInfo();
    printStudent2(stud);
    for (unsigned int i = 0; i < stud.size(); i++){
        std::vector<int> temp;
        temp = stud[i].nDarbas;
        std::cout << average2(stud[i].nDarbas) << std::endl;
    }
    // for (unsigned int i = 0; i < stud.size(); i++){
    //     if (average(stud[i].nDarbas) > 6.0){
    //         std::cout << average(stud[i].nDarbas) << std::endl;
    //         goodStud.push_back(stud[i]);
    //     }
    //     else {
    //         std::cout << average(stud[i].nDarbas) << std::endl;
    //         badStud.push_back(stud[i]);
    //     }
    // }
    // printStudentInfo();
    // for (unsigned int i = 0; i < badStud.size(); i++)
    //     std::cout << average(badStud[i].nDarbas) << std::endl;
}

void printStudent2(std::vector<Student> &stud){
    const int widthLong = 20;
    for (unsigned int i = 0; i < stud.size(); i++)
    std::cout << std::setw(widthLong) << std::fixed << std::setprecision(2) << average2(stud[i].nDarbas) << std::endl;
}

double average2(std::vector<int> &arr){
    int sum = 0;
    for (unsigned int i; i < arr.size(); i++)
        sum += arr[i];
    return static_cast<double>(sum)/arr.size();
}
