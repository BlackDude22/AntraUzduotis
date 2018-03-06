#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#include "student.h"
#include "antra_math.h"

int main(){
    for (int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<Student> students;
        const std::string fileName = "kursiokai" + std::to_string(i+1) + ".txt";
        createStudentFile(pow(10, i+3), fileName);
        readStudentsFromFile(students, fileName);
        std::vector<Student> losers;
        std::vector<Student> winners;
        for (auto& v : students){
            if (average(v.nDarbas) >= 6)
                winners.push_back(v);
            else losers.push_back(v);
        }
        std::cout << "Total: "<< students.size() << std::endl;
        std::cout << "Losers:" << losers.size() << std::endl;
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
    }

}
