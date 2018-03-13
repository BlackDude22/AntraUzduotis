#include <algorithm>
#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include "antra_math.h"

double average(std::vector<int> &arr){
    int sum = 0;
    for (unsigned int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return static_cast<double>(sum)/arr.size();
}

double median(std::vector<int> &arr){
    std::sort(arr.begin(), arr.end());
    if (arr.size()%2 == 1)
        return arr[arr.size()/2];
    else return static_cast<double>(arr[arr.size()/2]+arr[arr.size()/2-1])/2;
}

std::chrono::high_resolution_clock::time_point getTime(){
    return std::chrono::high_resolution_clock::now();
}

bool hasOnlyDigits(std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

std::string safeInput(){
    std::string input;
    getline(std::cin, input);
    std::cin.clear();
    return input;
}

int safeIntInput(){
    std::string input = safeInput();
    if (hasOnlyDigits(input))
        return std::stoi(input);
    else throw "Ivestas ne sveikasis skaicius";
}
