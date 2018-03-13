#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#include <deque>
#include <list>
#include "student.h"
#include "antra_math.h"

template<typename T> void fileTest(int fileCount){
    const int width = std::max(fileCount+2, 10);
    std::cout << std::setw(width) << std::right << " File size | Duration " << std::endl;
    for (int i = 1; i <= fileCount; i++){
        auto start = getTime();
        T students;
        const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
        readStudentsFromFile(students, fileName);
        sortContainer(students);
        T losers;
        T winners;
        for (auto& v : students){
            if (v.average >= 6)
                winners.push_back(v);
            else losers.push_back(v);
        }
        auto end = getTime();
        std::cout << std::setw(width) << students.size() << " | "<< std::chrono::duration<double>(end-start).count() << "s" << std::endl;
    }
}

int main(){
    // sugeneruojami 4 duomenu failai failai

    std::vector<Student> studentVector;
    while (true){
        std::string action;
        std::cout << "0: Nutraukti darba" << std::endl;
        std::cout << "1: Ivesti studenta" << std::endl;
        std::cout << "2: Nuskaityti is failo" << std::endl;
        std::cout << "3: Generuoti faila" << std::endl;
        std::cout << "4: Isvesti duomenu lentele" << std::endl;
        std::cout << "5: Testuoti konteinerius" << std::endl;
        std::cout << "Pasirinkite veiksma: ";
        getline(std::cin, action);
        std::cout << std::endl;

        if (action.compare("1") == 0){
            studentVector.push_back(Student());
            addStudentUI(studentVector.back());
        } else if (action.compare("2") == 0){
            std::string fileName;
            std::cout << "Iveskite failo pavadinima: ";
            getline(std::cin, fileName);
            readStudentsFromFile(studentVector, fileName);
        } else if (action.compare("3") == 0){
            std::string fileName, fileSize;
            std::cout << "Iveskite failo pavadinima: ";
            getline(std::cin, fileName);
            std::cout << "Iveskite studentu skaiciu: ";
            getline(std::cin, fileSize);
            if (hasOnlyDigits(fileSize))
                createStudentFile(std::stoi(fileSize), fileName);
            else std::cout << "Tokio atsakymo negali buti!" << std::endl;
        } else if (action.compare("4") == 0){
            printStudent(studentVector);
        } else if (action.compare("5") == 0){
            std::string fileCount;
            std::cout << "Iveskite didziausio failo dydzio laipsni(10^n): ";
            getline(std::cin, fileCount);
            if (hasOnlyDigits(fileCount)){
                for (int i = 1; i <= std::stoi(fileCount); i++){
                    auto start = getTime();
                    const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
                    std::cout << "generuojamas failas " + fileName + "..." << std::endl;
                    createStudentFile(static_cast<unsigned int>(pow(10, i)), fileName);
                    auto end = getTime();
                    std::cout << fileName + " sugeneruotas per " << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
                }

                //visi 4 failai nuskaitomi ir apdorojami su vectoriumi, list ir deque
                std::cout << " Vector: " << std::endl;
                fileTest<std::vector<Student>>(std::stoi(fileCount));

                std::cout << " List: " << std::endl;
                fileTest<std::list<Student>>(std::stoi(fileCount));

                std::cout << " Deque: " << std::endl;
                fileTest<std::deque<Student>>(std::stoi(fileCount));
            }
        } else if (action.compare("0") == 0){
            break;
        } else 
            std::cout << "Tokio veiksmo nera!" << std::endl;
        std::cout << std::endl;
    }
}
