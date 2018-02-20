#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

struct Student{
        std::string vardas;
        std::string pavarde;
        std::vector<int> nDarbas;
        int egzaminas;
        double mediana;
        double vidurkis;
};

char generateQuestion(std::string);
void generateRandomMarks(std::vector<int> &);
void generateMarks(std::vector<int> &);
int generateExam();
int generateRandomExam();
double median(std::vector<int> &, int);
double average(std::vector<int> &, int);

void addStudent(Student &, std::string, std::string, std::vector<int> &, int);
void addStudentManually(Student &);
void printStudent(Student &);
void printStudentInfo();

int main()
{
    std::vector<Student> stud;

    for (unsigned int i = 0; i < 3; i++){
        stud.push_back(Student());
        addStudentManually(stud[i]);
    }

    stud.push_back(Student());
    std::vector<int> paz(9,9);
    addStudent(stud[3], "Jonas", "Jonaitis", paz, 3);
    printStudentInfo();
    for (unsigned int i = 0; i < 4; i++)
        printStudent(stud[i]);
}

char generateQuestion(std::string text){
    char generuoti;
    while (true){
        std::cout << text;
        std::cin >> generuoti;
        if (generuoti == 't' || generuoti == 'T' || generuoti == 'n' || generuoti == 'N')
            break;
        else std::cout << "Tokio atsakymo nera!" << std::endl;
    }
    return generuoti;
}

void generateRandomMarks(std::vector<int> &marks){
    unsigned int i = 0;
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> mark(0,10);
    while (true){
        marks.push_back(mark(mt));
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
    auto i = 0;
    while (true){
        int temp;
        std::cout << i+1 << ". ";
        std::cin >> temp;
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

int generateExam(){
    int egzaminas;
    while(true){
        std::cout << "Egzamino pazymys: ";
        std::cin >> egzaminas;
        if (egzaminas < 1 || egzaminas > 10){
            std::cout << "Tokio pazymio negali buti!" << std::endl;
        }
        else break;
    }
    return egzaminas;
}

int generateRandomExam(){
    int egzaminas;
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> mark(1,10);
    std::cout << "Egzamino pazymys: ";
    egzaminas = mark(mt);
    std::cout << egzaminas << std::endl;
    return egzaminas;
}

double average(std::vector<int> &marks, int exam){
    int galBal = 0;
    for (unsigned int i; i < marks.size(); i++)
        galBal += marks[i];
    return 0.4*galBal/marks.size()+0.6*exam;
}

double median(std::vector<int> &marks, int exam){
    std::sort(marks.begin(), marks.end());
    double galBal = 0;
    if (marks.size()%2 == 1)
        galBal = marks[marks.size()/2];
    else galBal = (marks[marks.size()/2]+marks[marks.size()/2-1])/2;
    return 0.4*galBal+0.6*exam;
}

void addStudent(Student &stud, std::string name, std::string lastName, std::vector<int> &marks, int exam){
    stud.vardas = name;
    stud.pavarde = lastName;
    for (unsigned int i = 0; i < marks.size(); i++){
        stud.nDarbas.push_back(marks[i]);
    }
    stud.egzaminas = exam;
    stud.mediana = median(stud.nDarbas, stud.egzaminas);
    stud.vidurkis = average(stud.nDarbas, stud.egzaminas);
}

void addStudentManually(Student &stud){
    std::cout << std::endl;
    std::cout << "Studento vardas: ";
    std::cin >> stud.vardas;

    std::cout << "Studento pavarde: ";
    std::cin >> stud.pavarde;

    char generuoti = generateQuestion("Ar norite generuoti pazymius atsitiktinai?(t/n): ");

    std::cout << std::endl;
    std::cout << "Namu darbu pazymiai (Noredami baigti iveskite 0): " << std::endl;

    if (generuoti == 'n' || generuoti == 'N'){
        generateMarks(stud.nDarbas);
        stud.egzaminas = generateExam();
    }
    else if (generuoti == 't' || generuoti == 'T'){
        generateRandomMarks(stud.nDarbas);
        stud.egzaminas = generateRandomExam();
    }

    stud.mediana = median(stud.nDarbas, stud.egzaminas);
    stud.vidurkis = average(stud.nDarbas, stud.egzaminas);
    std::cout << std::endl;
}

void printStudent(Student &stud){
    //const int width = 10;
    const int widthLong = 20;
    std::cout << std::setw(widthLong) << stud.pavarde << std::setw(widthLong) <<  stud.vardas <<
                 std::setw(widthLong) << std::fixed << std::setprecision(2) << stud.vidurkis <<
                 std::setw(widthLong) << std::fixed << std::setprecision(2) << stud.mediana << std::endl;
}

void printStudentInfo(){
    //const int width = 10;
    const int widthLong = 20;
    std::cout << std::setw(widthLong) << "Pavarde" << std::setw(widthLong) <<  "Vardas" <<
                 std::setw(widthLong) << "Galutinis-vidurkis" << std::setw(widthLong) << "Galutinis-mediana" << std::endl;
}
