#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#include <deque>
#include <list>
#include "student.h"
#include "antra_math.h"

template<typename T> void fileTest1(int fileCount){
    const int width = std::max(fileCount+2, 10);
    std::cout << std::setw(width) << std::right << " File size | Duration " << std::endl;
    for (int i = 1; i <= fileCount; i++){
        auto start = getTime();
        T students;
        const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
        readStudentsFromFile(students, fileName);
        auto point2 = getTime();
        //sortContainer(students);
        const auto cSize = students.size();
        T losers;
        T winners;
        for (auto& v : students){
            if (compareByAverage(v))
                winners.push_back(v);
            else losers.push_back(v);
        }
        auto end = getTime();
        std::cout << std::setw(width) << cSize << " | " << std::chrono::duration<double>(end-start).count() << "s " << std::endl;
    }
}

bool compareByAverage(Student &stud){
    return stud.average*0.4+stud.egzaminas*0.6 >= 5;
}

template<typename T> void fileTest2(int fileCount){
    const int width = std::max(fileCount+2, 10);
    std::cout << std::setw(width) << std::right << " File size | Duration " << std::endl;
    for (int i = 1; i <= fileCount; i++){
        auto start = getTime();
        T students;
        const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
        readStudentsFromFile(students, fileName);
        //sortContainer(students);
        const auto vSize = students.size();
        auto pivot = std::partition(students.begin(), students.end(), compareByAverage);
        auto it = students.end();
        advance(it, -1);
        advance(pivot, -1);
        T losers;
        while (it != pivot){
            losers.push_back(*it);
            students.pop_back();
            it--;
        }
        auto end = getTime();
        std::cout << std::setw(width) << vSize << " | "<< std::chrono::duration<double>(end-start).count() << "s" << std::endl;
    }
}

template<typename T> void fileTestUI(std::string name, int fileCount){
    std::cout << std::endl << " -----"+name+"----- " << std::endl;
    std::cout << std::endl << " 1 strategija: " << std::endl;
    fileTest1<T>(fileCount);
    std::cout << std::endl << " 2 strategija: " << std::endl;
    fileTest2<T>(fileCount);    
    std::cout << std::endl;
}

int main(){
    std::vector<Student> studentVector;
    while (true){
        std::cout << "0: Nutraukti darba" << std::endl;
        std::cout << "1: Ivesti studenta" << std::endl;
        std::cout << "2: Nuskaityti is failo" << std::endl;
        std::cout << "3: Generuoti faila" << std::endl;
        std::cout << "4: Isvesti duomenu lentele" << std::endl;
        std::cout << "5: Testuoti konteinerius" << std::endl;
        std::cout << "Pasirinkite veiksma: ";
        std::string action = safeInput();

        if (action.compare("1") == 0){
            addStudentUI(studentVector);
        } else if (action.compare("2") == 0){
            std::string fileName;
            std::cout << "Iveskite failo pavadinima: ";
            fileName = safeInput();
            readStudentsFromFile(studentVector, fileName);
        } else if (action.compare("3") == 0){
            std::string fileName;
            int fileSize;
            std::cout << "Iveskite failo pavadinima: ";
            fileName = safeInput();
            std::cout << "Iveskite studentu skaiciu: ";
            try {
                fileSize = safeIntInput();
                createStudentFile(static_cast<unsigned int>(fileSize), fileName);
            } catch (const char* msg){
                std::cout << msg << std::endl;
            }
        } else if (action.compare("4") == 0){
            printStudent(studentVector);
        } else if (action.compare("5") == 0){
            int fileCount;
            std::cout << "Iveskite didziausio failo dydzio laipsni(10^n): ";
            try {
                fileCount = safeIntInput();
                //sugeneruojami duomenu failai
                for (int i = 1; i <= static_cast<int>(fileCount); i++){
                    auto start = getTime();
                    const std::string fileName = "kursiokai" + std::to_string(i) + ".txt";
                    std::cout << "generuojamas failas " + fileName + "..." << std::endl;
                    createStudentFile(static_cast<unsigned int>(pow(10, i)), fileName);
                    auto end = getTime();
                    std::cout << fileName + " sugeneruotas per " << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
                }

                //visi 4 failai nuskaitomi ir apdorojami su vectoriumi, list ir deque
                while (true){
                    std::cout << std::endl << "Pasirinkite konteineri, kuri norite isbandyti." << std::endl;
                    std::cout << "0: Grizti i meniu" << std::endl;
                    std::cout << "1: Vector" << std::endl;
                    std::cout << "2: List" << std::endl;
                    std::cout << "3: Deque" << std::endl;
                    std::cout << "Pasirinkite veiksma: ";
                    int containerAction = safeIntInput();
                    if (containerAction == 1)
                        fileTestUI<std::vector<Student>>("Vector", fileCount);
                    else if (containerAction == 2)
                        fileTestUI<std::list<Student>>("List", fileCount);
                    else if (containerAction == 3)
                        fileTestUI<std::deque<Student>>("Deque", fileCount);
                    else if (containerAction == 0)
                        break;
                    else std::cout << "Tokio veiksmo nera" << std::endl;
                }
            } catch (const char* msg){
                std::cout << msg << std::endl;
            }
                
        } else if (action.compare("0") == 0){
            break;
        } else 
            std::cout << "Tokio veiksmo nera!" << std::endl;
        std::cout << std::endl;
    }
}
