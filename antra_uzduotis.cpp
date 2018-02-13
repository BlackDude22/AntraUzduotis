#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

int main()
{
    std::cout << "Studento vardas: ";
    std::string vardas;
    std::cin >> vardas;

    std::cout << "Studento pavarde: ";
    std::string pavarde;
    std::cin >> pavarde;

    std::cout << "Namu darbu skaicius: ";
    int n = 0;
    std::cin >> n;

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

    std::vector<int> nDarbas(n);
    int i = 0;
    if (generuoti == 'n' || generuoti == 'N'){
        while (i < n){
            std::cout << i+1 << ". ";
            std::cin >> nDarbas[i];
            if (nDarbas[i] > 10 || nDarbas[i] < 1){
                std::cout << "Tokio pazymio negali buti!" << std::endl;
            }
            else i++;
        }
    }
    else if (generuoti == 't' || generuoti == 'T'){
        std::mt19937 mt(time(0));
        std::uniform_int_distribution<int> mark(1,10);
        while (i < n){
            nDarbas[i] = mark(mt);
            std::cout << i+1 << ". " << nDarbas[i] << std::endl;
            i++;
        }
    }

    std::cout << std::endl;
    int egzaminas;
    while(true){
        std::cout << "Egzamino pazymys: ";
        std::cin >> egzaminas;
        if (egzaminas < 1 || egzaminas > 10){
            std::cout << "Tokio pazymio negali buti!" << std::endl;
        }
        else break;
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
        for (int i = 0; i < n; i++)
            galBal += nDarbas[i];
        std::cout << std::fixed << std::setprecision(2) << 0.4*galBal/n+0.6*egzaminas << std::endl;
    }
    else if (mediana == 't' || mediana == 'T'){
        std::cout << "Galutinis balas: ";
        std::sort(nDarbas.begin(), nDarbas.end());
        double galBal = 0;
        if (n%2 == 1)
            galBal = nDarbas[n/2];
        else galBal = (double)(nDarbas[n/2]+nDarbas[n/2+1])/2;
        std::cout << std::fixed << std::setprecision(2) << 0.4*galBal+0.6*egzaminas << std::endl;
    }
}
