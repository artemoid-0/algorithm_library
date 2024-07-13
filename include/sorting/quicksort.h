#ifndef ALGORITHM_LIBRARY_QUICKSORT_H
#define ALGORITHM_LIBRARY_QUICKSORT_H

#include <vector>

template <typename T>
class QuickSort {
public:
    void sort(std::vector<T>& array);

private:
    void quicksort(std::vector<T>& array, int low, int high);
    int partition(std::vector<T>& array, int low, int high);
};

#endif //ALGORITHM_LIBRARY_QUICKSORT_H
