#include <iostream>
#include<vector>
#include <string>
#include<map>
#include <chrono>
#include <cstdint>
#include<ctime>
#include "BST.hpp"
#include"dataSruct.h"
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
