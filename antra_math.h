#ifndef ANTRA_MATH_H
#define ANTRA_MATH_H

#include <vector>
#include <chrono>

double average(std::vector<int> &);
double median(std::vector<int> &);
std::chrono::high_resolution_clock::time_point getTime();
bool hasOnlyDigits(std::string);

#endif
