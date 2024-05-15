#ifndef SORTINGLIB_H
#define SORTINGLIB_H

#include <vector>
#include<climate>
#include<algorthim>


class sort{
    public :
        void bubbleSort(std::vector<int>& arr);
        void selectionSort(std::vector<int>& arr);
        void insertionSort(std::vector<int>& arr);
        void mergeSort(std::vector<int>& arr);
        void quickSort(std::vector<int>& arr);
        void heapSort(std::vector<int>& arr);
        void countingSort(std::vector<int>& arr);
        void radixSort(std::vector<int>& arr);
        void bucketSort(std::vector<int>& arr);
        void shellSort(std::vector<int>& arr);
}

#endif // SORTINGLIB_H