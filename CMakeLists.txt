cmake_minimum_required(VERSION 3.10)
project(algorithm_library)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)

# Добавление директорий include и src в проект
include_directories(include)
include_directories(include/sorting)
include_directories(include/data_structures)
include_directories(include/graph_algorithms)
include_directories(include/optimization_algorithms)

# Добавление библиотек
add_library(sorting_lib
        src/sorting/quicksort.cpp
        src/sorting/mergesort.cpp
)

add_library(data_structures_lib
        src/data_structures/binary_tree.cpp
        src/data_structures/avl_tree.cpp
        src/data_structures/red_black_tree.cpp
)

add_library(graph_lib
        src/graph_algorithms/dfs.cpp
        src/graph_algorithms/bfs.cpp
)

add_library(optimization_lib
        src/optimization_algorithms/knapsack.cpp
        src/optimization_algorithms/lcs.cpp
)

# Добавление исходных файлов для тестов
add_executable(sorting_tests tests/sorting_tests.cpp)
add_executable(graph_tests tests/graph_algorithms_tests.cpp)
add_executable(optimization_tests tests/optimization_tests.cpp)

# Добавление зависимости от исходников библиотеки
target_link_libraries(sorting_tests sorting_lib)
target_link_libraries(graph_tests graph_lib)
target_link_libraries(optimization_tests optimization_lib)
