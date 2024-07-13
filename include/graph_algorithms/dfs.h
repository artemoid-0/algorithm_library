#ifndef ALGORITHM_LIBRARY_DFS_H
#define ALGORITHM_LIBRARY_DFS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

template <typename T>
class DFS {
public:
    DFS(const std::unordered_map<T, std::vector<T>>& graph);
    void search(const T& start);

private:
    void dfs(const T& node, std::unordered_set<T>& visited);

    const std::unordered_map<T, std::vector<T>>& graph;
};

#endif //ALGORITHM_LIBRARY_DFS_H
