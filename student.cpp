#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include <sstream>
#include "student.h"
#include "antra_math.h"

void addStudent(Student &stud, std::string name, std::string lastName, std::vector<int> &marks, int exam){
    stud.vardas = name;
    stud.pavarde = lastName;
    stud.nDarbas = marks;
    stud.egzaminas = exam;
}

void sortStudentByName(std::vector<Student> &stud){
    //naudojamas bubble sort algoritmas isrusiuoti studentams pagal pavardes
    for (unsigned int i = 0; i < stud.size()-1; i++)
        for (unsigned int j = i+1; j < stud.size(); j++){
            if (stud[i].pavarde.compare(stud[j].pavarde) > 0)
                std::swap(stud[i], stud[j]);
            else if(stud[i].pavarde.compare(stud[j].pavarde) == 0 && stud[i].vardas.compare(stud[j].vardas) > 0)
                std::swap(stud[i], stud[j]);
        }
}

void printStudent(std::vector<Student> &stud){
    const int width = 20, prec = 2;
    if (stud.size() > 0)
        sortStudentByName(stud);
    std::cout << std::setw(width) << "Pavarde" << std::setw(width) <<  "Vardas"
    << std::setw(width) << "Galutinis-vidurkis" << std::setw(width) << "Galutinis-mediana" << std::endl;
    //isvardijami visi vectoriuje stud saugomi studentai
    for (unsigned int i = 0; i < stud.size(); i++)
        std::cout << std::setw(width) << stud[i].pavarde << std::setw(width) << stud[i].vardas
        << std::setw(width) << std::fixed << std::setprecision(prec) << average(stud[i].nDarbas)*0.4+stud[i].egzaminas*0.6 
        << std::setw(width) << std::fixed << std::setprecision(prec) << median(stud[i].nDarbas)*0.4+stud[i].egzaminas*0.6 << std::endl;
}

void addStudentUI(Student &stud){
    std::string name, lastName, temp;
    std::vector<int> marks;
    int exam, tempInt;
    bool generateLogic = false;
    
    std::cout << "Vardas: "; std::cin >> name;
    std::cout << "Pavarde: "; std::cin >> lastName;
    //ivedama atsitiktinio generavimo logika
    //vedama tol kol ivedamas tinkamas atsakymas
    while (true){
        std::cout << "Ar norite generuoti pazymius atsitiktinai? (y/n): "; std::cin >> temp;
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
            if (!(std::cin >> tempInt)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Invalid input!" << std::endl;
            } else {
                if (tempInt <= 10 && tempInt >= 1){
                    marks.push_back(tempInt);
                    i++;
                }   
                else if (tempInt == 0)
                    break;
                else std::cout << "Invalid input!" << std::endl;
            }
        }
        while (true){
            int j = 0;
            std::cout << "Egzamino pazymys: ";
            if (!(std::cin >> tempInt)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Invalid input!" << std::endl;
            } else {
                if (tempInt <= 10 && tempInt >= 1){
                    exam = tempInt;
                    break;
                }   
                else if (tempInt == 0 && j == 0)
                    std::cout << "Invalid input!" << std::endl;
            }
        }
    }
    addStudent(stud, name, lastName, marks, exam);
}

void readStudentsFromFile(std::vector<Student> &stud, std::string fileName){
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
                stud.push_back(Student());
                addStudent(stud[static_cast<unsigned int>(stud.size()-1)],name, lastName, marks, exam);
            }
        }
        inf.close();
    } catch (std::ifstream::failure f){
        // sitas labai letina programos darba
        if (!inf.eof())
            std::cout << "Failed to read from " + fileName << std::endl;
        inf.clear();
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
