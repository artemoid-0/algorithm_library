#include <iostream>
#include <vector>
#include "sorting/quicksort.h"
#include "sorting/mergesort.h"

void test_quicksort() {
    QuickSort<int> qs;
    std::vector<int> array = {3, 6, 8, 10, 1, 2, 1};
    qs.sort(array);
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void test_mergesort() {
    MergeSort<int> ms;
    std::vector<int> array = {3, 6, 8, 10, 1, 2, 1};
    ms.sort(array);
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing QuickSort:" << std::endl;
    test_quicksort();

    std::cout << "Testing MergeSort:" << std::endl;
    test_mergesort();

    return 0;
}
