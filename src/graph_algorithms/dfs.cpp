#include "graph_algorithms/dfs.h"
#include <iostream>

template <typename T>
DFS<T>::DFS(const std::unordered_map<T, std::vector<T>>& graph) : graph(graph) {}

template <typename T>
void DFS<T>::search(const T& start) {
    std::unordered_set<T> visited;
    dfs(start, visited);
}

template <typename T>
void DFS<T>::dfs(const T& node, std::unordered_set<T>& visited) {
    if (visited.find(node) != visited.end()) {
        return;
    }

    visited.insert(node);
    std::cout << node << " ";

    for (const auto& neighbor : graph.at(node)) {
        dfs(neighbor, visited);
    }
}

// Explicit template instantiation
template class DFS<int>;
template class DFS<float>;
template class DFS<double>;
template class DFS<std::string>;
