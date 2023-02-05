//  Sorter.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 06 July 2022
//  CSCI 235 Project - IV
//
#include "Sorter.hpp"
/****************************************************************************************************************************
Description    :   implementation file of an integer array container class that
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.cpp
****************************************************************************************************************************/
using namespace std;

Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr)
{
}

/***************************s* Selection Sort ****************************/
template <typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp)
{
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (comp(arr[i], arr[min_or_max]))
        {
            min_or_max = i;
        }
    }
    return min_or_max;
}

// Swap function that swaps the value of two variable using a dummy variable temp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

template <typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp)
{
    // if the size is greater than 0 as the base case
    if (size>0){
        // first = index of the first item in the subarray of items yet to be sorted;
        for (int first = 0; first < size; first++) {
            // smallest_index = index of the smallest item
            int smallest_index=getPosOfMinOrMax(arr, first, size-1, comp);
            // Select the smallest entry in the_array[first ... size-1]
            if (arr[first] != arr[smallest_index]){
                // Swap the smallest entry, the_array[smallest_index], with
                // the first in the unsorted subarray the_array[first]
                swap(arr[smallest_index], arr[first]);
                // Incrementing the counter for selection sort
                selectionCount_++;
            }
        }
    }
    // return the total number of swaps
    return selectionCount_;
}

/************************************************************************/

/**************************** Insertion Sort ****************************/
template <typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp){
    // for loop that runs until the length of the array
    for(int j=1; j<size; j++){
        int key = arr[j]; // creating a key variable to store the element for comparision
        // Insert arr[j] into the sorted sequence
        int i = j-1;
        // while loops if i is greater than or equal to 1 and arr[i] is greater than the key
        while(i>=0 && comp(key,arr[i])){
            // moving the larger element to i+1 index of the array
            arr[i+1] = arr[i];
            i = i-1;
            // Incrementing the counter for insertion sort
            insertionCount_++;
        }
        // setting the key to the next
        arr[i+1] = key;
    }
    // return the total number of swaps
    return insertionCount_;
}
/************************************************************************/

// /****************************** Merge Sort ******************************/
template <typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp)
{
    int p = 0; // for index Left array
    int q = 0; // for index Right array
    int Merge_index = from; // for merge index starting from 'from'

    // from, mid, to are indices into arr[] where 'from <= mid < to'
    // Length of subarrays:
    int n1 = mid - from + 1;
    int n2 = to - mid;
    
    // New Arrays:
    // Let Left[1...n1+1] and Right[1...n2+1]
    int *Left = new int[n1];
    int *Right = new int[n2];
    
    // copying values to the new arrays
    // for i = 1 to n1
    for (int i = 0; i < n1; i++){
        // L[i] = arr[from + i ]
        Left[i] = arr[from + i ];
    }
    // for j = 1 to n2
    for (int j = 0; j < n2; j++){
        // R[j] = arr[mid + 1 + j]
        Right[j] = arr[mid + 1 + j];
    }

    // Merging the new arrays
    // while loops if the element in index 'i' and 'j' are less than the length of the subarrays
    while (p < n1 && q < n2){
        // if the element in the Left array of index 'i' is less than or equal to the element in the Right array of index 'j'
        if (comp(Left[p],Right[q])){
            arr[Merge_index] = Left[p];   // Insert the element from the Left array of index 'i' to the original array
            p++;    // Incrementing the index on the Left array
        }
        else {
            arr[Merge_index] = Right[q];  // Insert the element from the Right array of index 'i' to the original array
            q++;    // Incrementing the index on the Right array
        }
        Merge_index++;    // Incrementing the index on the original array
        mergeCount_++;   // Incrementing the counter for merge sort
    }
    
    // any left elements remaining will be added to the original array
    while (p < n1){     // while loops if the index 'i' is less than the length of the first subarray - Left
        arr[Merge_index] = Left[p];   // Insert the element from the Left array of index 'i' to the original array
        p++;    // Incrementing the index on the Left array
        Merge_index++;    // Incrementing the index on the original array
        mergeCount_++;  // Incrementing the counter for merge sort
    }
    
    // any right elements remaining will be added to the original array
    while (q < n2){    // while loops if the index 'j' is less than the length of the second subarray - Right
        arr[Merge_index] = Right[q];  // Insert the element from the Right array of index 'i' to the original array
        q++;    // Incrementing the index on the Right array
        Merge_index++;    // Incrementing the index on the original array
        mergeCount_++;  // Incrementing the counter for merge sort
    }
}

template <typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp)
{
    // base case
    if (from >= to)
        return 0;
    
    // calculating the mid = from + (to - from) / 2
    int mid = from + (to - from) / 2;
    // recursive function to sort the array from 'from' to 'mid'
    mergeSort(arr, from, mid, comp);
    // recursive function to sort the array from 'mid+1' to 'to'
    mergeSort(arr, mid + 1, to, comp);
    // recursive function to merge/join the sorted arrays into one
    merge(arr, from, mid, to, comp);
    // return the total number of swaps
    return mergeCount_;
}
// /************************************************************************/

void Sorter::runSorts(sort_order order)
{

    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];

    if (type_ == RANDOM)
    {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
        }
    }

    else
    {
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING)
    {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    }
    else
    {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING)
    {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    }
    else
    {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

    // Merge Sort Display
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING)
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    }
    else
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";

    selectionCount_ = 0;
    insertionCount_ = 0;
    mergeCount_ = 0;
}

void Sorter::displayArr(const int array[]) const
{
    for (size_t i = 0; i < SIZE_; i++)
    {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}
