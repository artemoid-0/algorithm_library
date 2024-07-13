#ifndef ALGORITHM_LIBRARY_BFS_H
#define ALGORITHM_LIBRARY_BFS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

template <typename T>
class BFS {
public:
    BFS(const std::unordered_map<T, std::vector<T>>& graph);
    void search(const T& start);

private:
    const std::unordered_map<T, std::vector<T>>& graph;
};


#endif //ALGORITHM_LIBRARY_BFS_H
