#ifndef ALGORITHM_LIBRARY_MERGESORT_H
#define ALGORITHM_LIBRARY_MERGESORT_H

#include <vector>

template <typename T>
class MergeSort {
public:
    void sort(std::vector<T>& array);

private:
    void mergesort(std::vector<T>& array, int left, int right);
    void merge(std::vector<T>& array, int left, int mid, int right);
};

#endif //ALGORITHM_LIBRARY_MERGESORT_H
