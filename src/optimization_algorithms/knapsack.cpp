#include "optimization_algorithms/knapsack.h"
#include <vector>
#include <algorithm>

Knapsack::Knapsack(int maxWeight, const std::vector<Item>& items)
        : maxWeight(maxWeight), items(items) {}

int Knapsack::solve() {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= maxWeight; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}
