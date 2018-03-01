#include <vector>
#include <iostream>
#include <string>
#include "student.h"
#include "antra_math.h"

int main(){
    
    // createStudentFile(10, "kursiokai1.txt");
    //     std::cout << "failas sukurtas" << std::endl;
    // createStudentFile(100, "kursiokai2.txt");
    //     std::cout << "failas sukurtas" << std::endl;
    // createStudentFile(1000, "kursiokai3.txt");
    //     std::cout << "failas sukurtas" << std::endl;
    // createStudentFile(10000, "kursiokai4.txt");
    //     std::cout << "failas sukurtas" << std::endl;
    for (int i = 0; i < 4; i++){
        std::vector<Student> students;
        std::string fileName = "kursiokai" + std::to_string(i+1) + ".txt";
        readStudentsFromFile(students, "kursiokai" + std::to_string(i+1) + ".txt");
        std::vector<Student> losers;
        std::vector<Student> winners;
        for (auto& v : students){
            if (average(v.nDarbas) >= 6)
                winners.push_back(v);
            else losers.push_back(v);
        }
        std::cout << i << std::endl;
    }
   //std::cout << getRandom(1, 10) << std::endl;
    //std::cout << "String" << sizeof(std::string) << " int" << sizeof(int) << " vector<int>" << sizeof(std::vector<int>) << std::endl;  


}
