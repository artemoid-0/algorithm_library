#include <iostream>
#include <unordered_map>
#include <vector>
#include "graph_algorithms/dfs.h"
#include "graph_algorithms/bfs.h"

void test_dfs() {
    std::unordered_map<int, std::vector<int>> graph = {
            {1, {2, 3}},
            {2, {4, 5}},
            {3, {6, 7}},
            {4, {}},
            {5, {}},
            {6, {}},
            {7, {}}
    };

    DFS<int> dfs(graph);
    std::cout << "DFS starting from node 1: ";
    dfs.search(1);
    std::cout << std::endl;
}

void test_bfs() {
    std::unordered_map<int, std::vector<int>> graph = {
            {1, {2, 3}},
            {2, {4, 5}},
            {3, {6, 7}},
            {4, {}},
            {5, {}},
            {6, {}},
            {7, {}}
    };

    BFS<int> bfs(graph);
    std::cout << "BFS starting from node 1: ";
    bfs.search(1);
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing DFS:" << std::endl;
    test_dfs();

    std::cout << "Testing BFS:" << std::endl;
    test_bfs();

    return 0;
}
