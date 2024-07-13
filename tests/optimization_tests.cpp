#include <iostream>
#include "optimization_algorithms/knapsack.h"
#include "optimization_algorithms/lcs.h"

void testKnapsack() {
    std::vector<Item> items = {{2, 3}, {3, 4}, {4, 5}, {5, 8}};
    int maxWeight = 5;

    Knapsack knapsack(maxWeight, items);
    int maxValue = knapsack.solve();

    std::cout << "Knapsack Maximum value: " << maxValue << std::endl;
}

void testLCS() {
    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB";

    LCS lcs(str1, str2);
    int lcsLength = lcs.solve();

    std::cout << "LCS Length: " << lcsLength << std::endl;
}

int main() {
    testKnapsack();
    testLCS();
    return 0;
}
