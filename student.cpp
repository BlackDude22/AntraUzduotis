#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <fstream>
#include "student.h"
#include "antra_math.h"

void generateRandomMarks(std::vector<int> &marks){
    unsigned int i = 0;
    while (true){
        marks.push_back(getRandom(0, 10));
        std::cout << i+1 << ". " << marks[i] << std::endl;
        if (marks[i] == 0 && i == 0){
           marks.pop_back();
           std::cout << "Iveskite bent viena pazymi!" << std::endl;
        }
        else if (marks[i] == 0){
            marks.pop_back();
            break;
            }
        else i++;
    }
}

void generateMarks(std::vector<int> &marks){
    int i = 0;
    while (true){
        int temp;
        std::cout << i+1 << ". ";
        if (!(std::cin >> temp)){
            std::cin.clear();
            std::cin.ignore();
        }
        if (temp == 0 && i == 0){
            std::cout << "Iveskite bent viena pazymi!" << std::endl;
        }
        else if (temp == 0){
            break;
            }
        else if (temp > 10 || temp < 1){
            std::cout << "Tokio pazymio negali buti!" << std::endl;
        }
        else {
            marks.push_back(temp);
            i++;
        }
    }
}

void addStudent(Student &stud){
    std::cout << std::endl;
    std::cout << "Studento vardas: ";
    std::cin >> stud.vardas;

    std::cout << "Studento pavarde: ";
    std::cin >> stud.pavarde;

    char generuoti;
    while (true){
        std::cout << "Ar norite generuoti pazymius atsitiktinai?(t/n): ";
        std::cin >> generuoti;
        if (generuoti == 't' || generuoti == 'T' || generuoti == 'n' || generuoti == 'N')
            break;
        else std::cout << "Tokio atsakymo nera!" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Namu darbu pazymiai (Noredami baigti iveskite 0): " << std::endl;

    if (generuoti == 'n' || generuoti == 'N'){
        generateMarks(stud.nDarbas);
        while(true){
        	std::cout << "Egzamino pazymys: ";
        	if (!(std::cin >> stud.egzaminas)){
            	std::cin.clear();
            	std::cin.ignore();
        	}
        	if (stud.egzaminas < 1 || stud.egzaminas > 10){
            	std::cout << "Tokio pazymio negali buti!" << std::endl;
        	}
        	else break;
    	}
    }
    else if (generuoti == 't' || generuoti == 'T'){
        generateRandomMarks(stud.nDarbas);
        stud.egzaminas = getRandom(1,10);
    }

    std::cout << std::endl;
}

void printStudent(Student &stud){
    const int widthLong = 20;
    std::cout << std::setw(widthLong) << stud.pavarde << std::setw(widthLong) <<  stud.vardas <<
                 std::setw(widthLong) << std::fixed << std::setprecision(2) << average(stud.nDarbas)/**0.4+stud.egzaminas*0.6*/ <<
                 std::setw(widthLong) << std::fixed << std::setprecision(2) << median(stud.nDarbas)*0.4+stud.egzaminas*0.6 << std::endl;
}

void printStudentInfo(){
    const int widthLong = 20;
    std::cout << std::setw(widthLong) << "Pavarde" << std::setw(widthLong) <<  "Vardas" <<
                 std::setw(widthLong) << "Galutinis-vidurkis" << std::setw(widthLong) << "Galutinis-mediana" << std::endl;
}

void readStudentsFromFile(std::vector<Student> &stud, std::string fileName){
    std::ifstream inf(fileName);
    if (inf.good()) {
        std::string singleLine;
        while(getline(inf, singleLine)) {
            std::istringstream ss(singleLine);
            std::vector<std::string> words;
            std::string temp;
            while (ss >> temp)
                words.push_back(temp);
            if (words.size() > 3) {            
                std::string name = words[0], lastName = words[1];
                std::vector<int> marks;
                for (unsigned int i = 2; i < words.size()-1; i++)
                    marks.push_back(stoi(words[i]));
                int exam = stoi(words[static_cast<unsigned int>(words.size()-1)]);
                stud.push_back(Student());
                stud[static_cast<unsigned int>(stud.size()-1)] = {name, lastName, marks, exam};
            }
        }
    }
    inf.close();
}

void createStudentFile(int fSize, std::string fileName){
    std::ofstream outf(fileName);
    for (unsigned int i = 0; i < fSize; i++){
        outf << "Vardas"+std::to_string(i)+" Pavarde"+std::to_string(i)+" ";
        for (unsigned int j = 0; j < getRandom(2, 10); j++)
            outf << std::to_string(getRandom(1,10))+" ";
        outf << std::endl;
    }
}
