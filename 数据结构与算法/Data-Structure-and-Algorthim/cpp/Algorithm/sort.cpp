#include<sort.h>

void sort::bubbleSort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

void sort::selectionSort(vector<int>&arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // 初始化当前最小值的索引为i
        for (int j = i + 1; j < n; j++) {
            // 查找最小值的索引
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // 交换当前位置i和最小值位置minIdx的元素
        std::swap(arr[i], arr[minIdx]);
    }
}

