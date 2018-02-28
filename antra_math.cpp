#include <algorithm>
#include <vector>
#include "antra_math.h"

double average(std::vector<int> &arr){
    int sum = 0;
    for (unsigned int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    return static_cast<double>(sum)/arr.size();
}

double median(std::vector<int> &arr){
    std::sort(arr.begin(), arr.end());
    double median;
    if (arr.size()%2 == 1)
        median = arr[arr.size()/2];
    else median = static_cast<double>(arr[arr.size()/2]+arr[arr.size()/2-1])/2;
    return median;
}
