#include <iostream>
#include<vector>
#include <string>
#include<map>
#include <chrono>
#include <cstdint>
#include<ctime>
#include "BST.hpp"
#include"dataSruct.h"

void print(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << array[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
}

void print(const std::vector<int> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << " value is:" << v[i] << std::endl;
    }
}

int __selectMax(int *array, int n) {
    int max = *array;
    for (int i = 0; i < n; ++i) {
        if (max < *(array + i))
            max = *(array + i);
    }
    return max;
}

int __selectMin(int *array, int n) {
    int min = *array;
    for (int i = 0; i < n; ++i) {
        if (min > *(array + n * i))
            min = *(array + n * i);
    }
    return min;
}

void exp1() {
    int n;
    std::cin >> n;
    int *array_2d = new int[n * n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> array_2d[i * n + j];
        }
    }
    std::cout << "your input:" << std::endl;
    print(array_2d, n);

    std::vector<int> line_max_array;
    std::vector<int> list_min_array;
    std::map<std::string, int> res;
    for (int i = 0; i < n; ++i) {
        int max = __selectMax(&array_2d[i * n], n);
        line_max_array.push_back(max);
    }
    std::cout << "max value array is:" << std::endl;
    print(line_max_array, n);

    for (int i = 0; i < n; ++i) {
        int min = __selectMin(&array_2d[i], n);
        list_min_array.push_back(min);
    }
    std::cout << "min value array is:" << std::endl;
    print(list_min_array, n);
    for (int i = 0; i < n; ++i) {
        using namespace std;
        for (int j = 0; j < n; ++j) {
            if (array_2d[i * n + j] == line_max_array[i] && array_2d[i * n + j] == list_min_array[j])
                res["(" + to_string(i + 1) + "," + to_string(j + 1) + ")"] = array_2d[i * n + j];
        }
    }
    std::cout << "saddle point is :";
    for (auto it = res.begin(); it != res.end(); ++it) {
        std::cout << it->first << ' ' << it->second << std::endl;
    }
}


//exp 3
void __randomInit() {
    using namespace std::chrono;
    uint64_t num = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    srand(num);
}

void exp3() {
    __randomInit();
    BST<int, int> bst;
    const int times = 100;
    for (int i = 0; i < times; ++i) {
        bst.insert(rand(), rand());
    }
    bst.levelOrder();

}

int main() {
    using namespace std;
    Graph_undirect_net<string> g(50);

    g.addEdge(make_tuple("v1",
                         "v2",
                         3));
    g.addEdge(make_tuple("v1",
                         "v6",
                         6));
    g.addEdge(make_tuple("v1",
                         "v3",
                         2));
    g.addEdge(make_tuple("v1",
                         "v4",
                         4));
    g.addEdge(make_tuple("v2",
                         "v5",
                         4));
    g.addEdge(make_tuple("v2",
                         "v3",
                         1));
    g.addEdge(make_tuple("v3",
                         "v4",
                         1));
    g.addEdge(make_tuple("v3",
                         "v5",
                         3));
    g.addEdge(make_tuple("v6",
                         "v4",
                         3));
    g.addEdge(make_tuple("v5",
                         "v4",
                         5));
    g.addEdge(make_tuple("v4",
                         "v7",
                         5));
    g.addEdge(make_tuple("v5",
                         "v7",
                         7));
    g.addEdge(make_tuple("v6",
                         "v7",
                         6));

    Graph_undirect_net<string> min_tree=g.primMakeSmallestTree();
    min_tree.printAll();

    return 0;
}
