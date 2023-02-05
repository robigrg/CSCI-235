//  main.cpp
// Name: Robi Gurung
// CSCI 235
// 

#include "Sorter.hpp"
#include <iostream>

int main(){
    Sorter abc(RANDOM, 10);
    abc.runSorts(DECREASING);
    
    
    int arr[] = {91, 24, 29, 37, 77, 19, 54, 11, 16, 75};
    /*
        Start: 12, 39, 2, 58, 74, 26, 81, 63, 36, 62
        i = 0
    */
    

    Sorter s(PREDETERMINED, 10, arr);
    s.runSorts(INCREASING);
    
    // Sorter::mergeSort(arr,std::greater<int>{});
    return 0;
}
