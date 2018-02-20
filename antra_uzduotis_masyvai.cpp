#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

class FakeVector {
private:
    int nSize = 1, elementCount = 0;
    int* arr = new int[nSize];
    void increaseVector();
public:
    void pushBack(int);
    void popBack();
    void sortVector();
    void print();
    int getSize(){return elementCount;}
    int get(int);
};

void FakeVector::pushBack(int n){
    if (elementCount < nSize)
        arr[elementCount] = n;
    else {
        increaseVector();
        arr[elementCount] = n;
    }
    elementCount++;
}

void FakeVector::popBack(){
    if (elementCount > 0){
        arr[elementCount] = 0;
        elementCount--;
    }
}

void FakeVector::increaseVector(){
    nSize *= 2;
    int* nArr = new int[nSize];
    for (int i = 0; i < nSize/2; i++){
        nArr[i] = arr[i];
    }
    delete[] arr;
    arr = nArr;
}

void FakeVector::print(){
    for (int i = 0; i < elementCount; i++){
        std::cout << i+1 << ". " << arr[i] << std::endl;
    }
}

int FakeVector::get(int i){
    return arr[i];
}

void FakeVector::sortVector(){
    for (int i = 0; i < elementCount-1; i++){
        for (int j = i+1; j < elementCount; j++){
            if (arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{
    std::cout << "Studento vardas: ";
    std::string vardas;
    std::cin >> vardas;

    std::cout << "Studento pavarde: ";
    std::string pavarde;
    std::cin >> pavarde;

    char generuoti;
    while (true){
        std::cout << "Ar norite generuoti pazymius atsitiktinai?(t/n): ";
        std::cin >> generuoti;
        if (generuoti == 't' || generuoti == 'T' || generuoti == 'n' || generuoti == 'N')
            break;
        else std::cout << "Tokio atsakymo nera!" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Namu darbu pazymiai: " << std::endl;

    FakeVector nDarbas;
    if (generuoti == 'n' || generuoti == 'N'){
        int i = 0;
        while (true){
            int temp;
            std::cout << i+1 << ". ";
            std::cin >> temp;
            nDarbas.pushBack(temp);
            if (nDarbas.get(i) == 0 && i == 0){
                nDarbas.popBack();
                std::cout << "Iveskite bent viena pazymi!" << std::endl;
            }
            else if (nDarbas.get(i) == 0){
                nDarbas.popBack();
                break;
                }
            else if (nDarbas.get(i) > 10 || nDarbas.get(i) < 1){
                nDarbas.popBack();
                std::cout << "Tokio pazymio negali buti!" << std::endl;
            }
            else i++;
        }
    }
    else if (generuoti == 't' || generuoti == 'T'){
       int i = 0;
        std::mt19937 mt(time(nullptr));
        std::uniform_int_distribution<int> mark(0,10);
        while (true){
            nDarbas.pushBack(mark(mt));
            std::cout << i+1 << ". " << nDarbas.get(i) << std::endl;
            if (nDarbas.get(i) == 0 && i == 0){
                nDarbas.popBack();
                std::cout << "Iveskite bent viena pazymi!" << std::endl;
            }
            else if (nDarbas.get(i) == 0){
                nDarbas.popBack();
                break;
                }
            else i++;
        }
    }

    std::cout << std::endl;
    int egzaminas;
    while(true){
        std::cout << "Egzamino pazymys: ";
        std::cin >> egzaminas;
        if (egzaminas < 1 || egzaminas > 10){
            std::cout << "Tokio pazymio negali buti!" << std::endl;
        } else break;
    }

    char mediana;
    while (true){
        std::cout << "Ar pazymiui skaiciuoti norite naudoti mediana?(t/n): ";
        std::cin >> mediana;
        if (mediana == 't' || mediana == 'T' || mediana == 'n' || mediana == 'N')
            break;
        else std::cout << "Tokio atsakymo nera!" << std::endl;
    }

    if(mediana == 'n' || mediana == 'N'){
        std::cout << "Galutinis balas: ";
        int galBal = 0;
        for (int i = 0; i < nDarbas.getSize(); i++)
            galBal += nDarbas.get(i);
        std::cout << std::fixed << std::setprecision(2) << 0.4*galBal/nDarbas.getSize()+0.6*egzaminas << std::endl;
    }
    else if (mediana == 't' || mediana == 'T'){
        std::cout << "Galutinis balas: ";
        nDarbas.sortVector();
        double galBal = 0;
        if (nDarbas.getSize()%2 == 1)
            galBal = nDarbas.get(nDarbas.getSize()/2);
        else galBal = (double)(nDarbas.get(nDarbas.getSize()/2)+nDarbas.get(nDarbas.getSize()/2-1)/2);
        std::cout << std::fixed << std::setprecision(2) << 0.4*galBal+0.6*egzaminas << std::endl;
    }
}
