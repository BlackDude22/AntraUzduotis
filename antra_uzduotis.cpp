#include <vector>
#include <iostream>
#include "student.h"
#include "antra_math.h"

int main(){
    std::vector<Student> students;
    createStudentFile(15, "kursiokai.txt");
    readStudentsFromFile(students, "kursiokai.txt");
    printStudent(students);
    std::cout << "String" << sizeof(std::string) << " int" << sizeof(int) << " vector<int>" << sizeof(std::vector<int>) << std::endl;  


}
