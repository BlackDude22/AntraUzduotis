#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <deque>
#include <list>
#include "student.h"
#include "antra_math.h"

void addStudentUI(std::vector<Student> &stud){
    std::string name, lastName, temp;
    std::vector<int> marks;
    int exam, tempInt;
    bool generateLogic = false;
    
    std::cout << "Vardas: ";
    name = safeInput();
    std::cout << "Pavarde: ";
    lastName = safeInput();
    //ivedama atsitiktinio generavimo logika
    //vedama tol kol ivedamas tinkamas atsakymas
    while (true){
        std::cout << "Ar norite generuoti pazymius atsitiktinai? (y/n): ";
        temp = safeInput();
        if (temp.compare("y") == 0 || temp.compare("Y") == 0){
            generateLogic = true;
            break;
        } else if (temp.compare("n") == 0 || temp.compare("N") == 0)
            break;
    }
    
    std::cout << "Iveskite pazymius (noredami baigti veskite 0): " << std::endl;

    if (generateLogic){
        std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
        std::uniform_int_distribution<int> mark(1,10);
        //sugeneruojamas atsitiktinis atsitiktiniu pazymiu skaicius
        for (unsigned int i = 0; i < static_cast<unsigned int>(mark(mt)); i++){
            marks.push_back(mark(mt));
            std::cout << i+1 << ". " << marks[i] << std::endl;
        }  
        exam = mark(mt);
        std::cout << "Egzamino pazymys: " << exam << std::endl;
    } else {
        int i = 0;
        //ranka ivedami duomenys tol kol nutraukiamas ciklas
        while (true){
            std::cout << i+1 << ". ";
            try {
                tempInt = safeIntInput();
                if (tempInt <= 10 && tempInt >= 1){
                    marks.push_back(tempInt);
                    i++;
                } else if (tempInt == 0 && i == 0){
                    std::cout << "Iveskite bent viena pazymi!" << std::endl;
                } else if (tempInt == 0 && i != 0){
                    break;
                } else std::cout << "Tokio pazymio negali buti" << std::endl;
            } catch (const char* msg){
                std::cout << msg << std::endl;
            }
        }
        while (true){
            std::cout << "Egzamino pazymys: ";
            try{
                tempInt = safeIntInput();
                if (tempInt <= 10 && tempInt >= 1){
                    exam = tempInt;
                    break;
                } else std::cout << "Tokio pazymio negali buti!" << std::endl;
            } catch (const char* msg){
                std::cout << msg << std::endl;
            }
        }
    }
    try {
        addStudent(stud, name, lastName, marks, exam);
    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
    
}

void createStudentFile(unsigned int fSize, std::string fileName){
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> mark(1,10);
    std::ofstream outf(fileName);
    //generuojamas studento irasas
    for (unsigned int i = 0; i < fSize; i++){
        outf << "Pavarde" << i << " Vardas" << i;
        //sugeneruojamas atsitiktinis skaicius atsitiktiniu pazymiu
        for (int j = 0; j < mark(mt)+1; j++)
            outf << " " << mark(mt);
        outf << std::endl;
    }
    outf.close();
}

bool customCompare(Student &stud1, Student &stud2){
    return stud1.pavarde < stud2.pavarde;
}

template <> void sortContainer(std::vector<Student> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}

template <> void sortContainer(std::deque<Student> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}

template <> void sortContainer(std::list<Student> &stud){
    stud.sort(customCompare);
}
