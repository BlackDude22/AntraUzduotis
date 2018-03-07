#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#include <deque>
#include <list>
#include "student.h"
#include "antra_math.h"

template<typename T> void fileTest(T &containerType, std::string type, int fileCount){
    std::cout << std::endl << " " + type + ": " << std::endl;
    const int width = std::max(fileCount+2, 10);
    std::cout << std::setw(width) << std::right << " File size | Duration " << std::endl;
    for (int i = 1; i <= fileCount; i++){
        auto start = getTime();
        T students;
        const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
        readStudentsFromFile(students, fileName);
        T losers;
        T winners;
        for (auto& v : students){
            if (average(v.nDarbas) >= 6)
                winners.push_back(v);
            else losers.push_back(v);
        }
        sortContainer(students);
        auto end = getTime();
        std::cout << std::setw(width) << students.size() << " | "<< std::chrono::duration<double>(end-start).count() << "s" << std::endl;
    }
}

int main(){
    // sugeneruojami 4 duomenu failai failai
    const int fileCount = 6;

    for (int i = 1; i <= fileCount; i++){
        const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
        std::cout << "generuojamas failas " + fileName + "..." << std::endl;
        createStudentFile(static_cast<unsigned int>(pow(10, i)), fileName);
        std::cout << fileName + " sugeneruotas" << std::endl;
    }

    //visi 4 failai nuskaitomi ir apdorojami su vectoriumi, list ir deque
    std::vector<Student> students1;
    fileTest(students1, "Vector", fileCount);

    std::list<Student> students2;
    fileTest(students2, "List", fileCount);

    std::deque<Student> students3;
    fileTest(students3, "Deque", fileCount);
}
