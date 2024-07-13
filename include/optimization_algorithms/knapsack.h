#ifndef ALGORITHM_LIBRARY_KNAPSACK_H
#define ALGORITHM_LIBRARY_KNAPSACK_H

#include <vector>

struct Item {
    int weight;
    int value;
};

class Knapsack {
public:
    Knapsack(int maxWeight, const std::vector<Item>& items);

    int solve();

private:
    int maxWeight;
    std::vector<Item> items;
};

#endif // ALGORITHM_LIBRARY_KNAPSACK_H

