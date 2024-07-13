#include "sorting/quicksort.h"

template <typename T>
void QuickSort<T>::sort(std::vector<T>& array) {
    quicksort(array, 0, array.size() - 1);
}

template <typename T>
void QuickSort<T>::quicksort(std::vector<T>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

template <typename T>
int QuickSort<T>::partition(std::vector<T>& array, int low, int high) {
    T pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

// Explicit template instantiation
template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<double>;
