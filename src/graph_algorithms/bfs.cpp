#include "graph_algorithms/bfs.h"
#include <iostream>

template <typename T>
BFS<T>::BFS(const std::unordered_map<T, std::vector<T>>& graph) : graph(graph) {}

template <typename T>
void BFS<T>::search(const T& start) {
    std::unordered_set<T> visited;
    std::queue<T> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        T node = q.front();
        q.pop();
        std::cout << node << " ";

        for (const auto& neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

// Explicit template instantiation
template class BFS<int>;
template class BFS<float>;
template class BFS<double>;
template class BFS<std::string>;
