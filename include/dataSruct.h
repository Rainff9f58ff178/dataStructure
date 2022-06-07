//
// Created by rain on 2022/5/23.
//

#ifndef ALG_DATASRUCT_H
#define ALG_DATASRUCT_H

#include<vector>
#include<set>
#include<tuple>
#include<iostream>
#include <algorithm>
#include<queue>
#include <assert.h>
#include<string>
template<class VertexType>
class Graph_directed_net {
public:
    typedef
    std::vector<std::tuple<VertexType, VertexType, int>>
            tuple_vertex_array;

private:
    static const int __INFINITE = __INT32_MAX__;
    const int __max_vertex_num;
    std::vector<VertexType> __vertexArray;
    std::vector<std::vector<int>> __adjacency_matrix_graph;
    int __current_vertex;
    int __current_edge;
public:
    Graph_directed_net() {}

    Graph_directed_net(const tuple_vertex_array &vertexTuple, //顶点,顶点,权值
                       const std::vector<VertexType> &vertexArray, //顶点数组
                       const int &maxVertexNum, //最大顶点数
                       const int &vertexNum    //顶点数
    ) //边数
            : __max_vertex_num(maxVertexNum),
              __current_vertex(vertexNum), __current_edge(0) {
        __vertexArray = vertexArray;
        __adjacency_matrix_graph.reserve(__max_vertex_num);
        for (int i = 0; i < __max_vertex_num; ++i) {
            for (int j = 0; j < __max_vertex_num; ++j)
                __adjacency_matrix_graph[i].reserve(__max_vertex_num);
        }
        for (int i = 0; i < __max_vertex_num; ++i)
            for (int j = 0; j < __max_vertex_num; ++j)
                __adjacency_matrix_graph[i][j] = __INFINITE;

        for (int i = 0; i < vertexTuple.size(); ++i) {
            addEdge(vertexTuple[i]);
        }
    }

    bool
    addEdge(const std::tuple<VertexType, VertexType, int> &vertexTuple) {

        if (!std::count(__vertexArray.begin(),
                        __vertexArray.end(),
                        std::get<0>(vertexTuple))) {
            __vertexArray.push_back(std::get<0>(vertexTuple));
            __current_vertex++;
        }
        if (!std::count(__vertexArray.begin(),
                        __vertexArray.end(),
                        std::get<1>(vertexTuple))) {
            __vertexArray.push_back(std::get<1>(vertexTuple));
            __current_vertex++;
        }

        int index_vertexF = __locateVexindex(
                std::get<0>(vertexTuple));
        int index_vertexS = __locateVexindex(
                std::get<1>(vertexTuple));
        //set value of net
        if (__adjacency_matrix_graph[index_vertexF][index_vertexS] ==
            __INFINITE) {
            __adjacency_matrix_graph[index_vertexF][index_vertexS] =
                    std::get<2>(vertexTuple);
            __current_edge++;
        } else {
            __adjacency_matrix_graph[index_vertexF][index_vertexS] =
                    std::get<2>(vertexTuple);
        }


    }

public:
    void
    printAll() {

        for (int i = 0; i < __current_vertex; ++i) {
            for (int j = 0; j < __current_vertex; ++j) {
                if (__adjacency_matrix_graph[i][j] != __INFINITE)
                    std::cout << __vertexArray[i]
                              << " "
                              << __vertexArray[j]
                              << " "
                              << __adjacency_matrix_graph[i][j] << std::endl;
            }
            std::cout << std::endl;
        }
    }

private:
    int
    __locateVexindex(const VertexType &vertex) {
        for (int i = 0; i < __current_vertex; ++i) {
            if (__vertexArray[i] == vertex)
                return i;
        }
        return -1;
    }
};

template<class VertexType>
class Graph_undirect_net {
public:
    typedef
    std::vector<std::tuple<VertexType, VertexType, int>>
            tuple_vertex_array;


private:
    static const int __INIFNITE = __INT32_MAX__;
    std::vector<VertexType> __vertex_array;
    std::vector<std::vector<int>> __adjacency_matrix_graph;
    int __current_vertex;
    int __current_edge;

public:
    Graph_undirect_net() = delete;

    Graph_undirect_net(const int &maxVertexNum) : __current_vertex(0), __current_edge(0) {
        __adjacency_matrix_graph.reserve(maxVertexNum);
        for (int i = 0; i < maxVertexNum; ++i)
            __adjacency_matrix_graph[i].reserve(maxVertexNum);
        for (int i = 0; i < maxVertexNum; ++i)
            for (int j = 0; j < maxVertexNum; ++j)
                __adjacency_matrix_graph[i][j] = __INIFNITE;

    }

    bool addVertex(VertexType vertex) {
        __vertex_array.push_back(vertex);
    }

    bool addEdge(std::tuple<VertexType, VertexType, int> vertexTuple) {
        if (!std::count(__vertex_array.begin(),
                        __vertex_array.end(),
                        std::get<0>(vertexTuple))) {
            __vertex_array.push_back(std::get<0>(vertexTuple));
            __current_vertex++;
        }
        if (!std::count(__vertex_array.begin(),
                        __vertex_array.end(),
                        std::get<1>(vertexTuple))) {
            __vertex_array.push_back(std::get<1>(vertexTuple));
            __current_vertex++;
        }
        int vertex_index_f = __getIndexOfVertex(
                std::get<0>(vertexTuple));
        int vertex_index_s = __getIndexOfVertex(
                std::get<1>(vertexTuple));

        if (__adjacency_matrix_graph[vertex_index_f][vertex_index_s] ==
            __INIFNITE) {
            __adjacency_matrix_graph[vertex_index_f][vertex_index_s] =
                    std::get<2>(vertexTuple);
            __adjacency_matrix_graph[vertex_index_s][vertex_index_f] =
                    std::get<2>(vertexTuple);
            __current_edge++;
        } else {
            __adjacency_matrix_graph[vertex_index_f][vertex_index_s] =
                    std::get<2>(vertexTuple);
            __adjacency_matrix_graph[vertex_index_s][vertex_index_f] =
                    std::get<2>(vertexTuple);
        }

    }

    void
    printAll() {
        std::vector<std::tuple<VertexType, VertexType, int>> v;
        for (int i = 0; i < __current_vertex; ++i)
            for (int j = 0; j < __current_vertex; ++j)
                if (__adjacency_matrix_graph[i][j] != __INIFNITE)
                    if (!std::count(v.begin(),
                                    v.end(),
                                    std::make_tuple(
                                            __vertex_array[i],
                                            __vertex_array[j],
                                            __adjacency_matrix_graph[i][j]
                                    )) && !std::count(v.begin(),
                                                      v.end(),
                                                      std::make_tuple(
                                                              __vertex_array[j],
                                                              __vertex_array[i],
                                                              __adjacency_matrix_graph[i][j]
                                                      )))
                        v.push_back(std::make_tuple(
                                __vertex_array[i],
                                __vertex_array[j],
                                __adjacency_matrix_graph[i][j]
                        ));


        for (int i = 0; i < v.size(); ++i)
            std::cout << std::get<0>(v[i])
                      << " "
                      << std::get<1>(v[i])
                      << " "
                      << std::get<2>(v[i])
                      << std::endl;
    }

    void DFS() {
        std::vector<int> traverse_arr;
        traverse_arr.reserve(__current_vertex);
        for (int i = 0; i < __vertex_array.size(); ++i)
            __DFS(i, traverse_arr);
    }



    void BFS2() {
        std::vector<int> traversed_arr;
        traversed_arr.reserve(__current_vertex);
        for (int i = 0; i < __current_vertex; ++i)
            if (!std::count(traversed_arr.begin(),
                            traversed_arr.end(),
                            i))
                __BFS2(i, traversed_arr);
    }

    void BFS2_DEBUG() {
        std::vector<int> traversed_arr;
        traversed_arr.reserve(__current_vertex);
        for (int i = 0; i < __current_vertex; ++i)
            if (!std::count(traversed_arr.begin(),
                            traversed_arr.end(),
                            i))
                __BFS2_DEBUG(i, traversed_arr);
    }

    Graph_undirect_net<VertexType> BFSMakeTree() {
        Graph_undirect_net<VertexType> g(__current_vertex);
        std::vector<int> traversed_arr;
        traversed_arr.reserve(__current_vertex);
        for (int i = 0; i < __current_vertex; ++i)
            if (!std::count(traversed_arr.begin(),
                            traversed_arr.end(),
                            i))
                __BFSMakeTree(i, traversed_arr, g);
        return g;
    }

    int getEdge(VertexType v1, VertexType v2) {
        int edge_value =
                __adjacency_matrix_graph[__getIndexOfVertex(v1)][__getIndexOfVertex(v2)];
        return edge_value;
    }

    int getVertexNum() {
        return __vertex_array.size();
    }

    std::vector<std::vector<int>> getAdjecentMatrix() {
        return __adjacency_matrix_graph;
    }

    bool vertifyIsMakeTree(Graph_undirect_net<VertexType> &g_other) {
        bool flag = false;
        for (int i = 0; i < __current_vertex; ++i) {
            for (int j = 0; j < __current_vertex; ++j) {
                if (__adjacency_matrix_graph[i][j] !=
                    g_other.getEdge(__vertex_array[i], __vertex_array[j]))
                    flag = true;
            }
        }
        return flag;
    }

    Graph_undirect_net<VertexType> primMakeSmallestTree() {
        Graph_undirect_net<VertexType> smallest_tree(__current_vertex);
        std::vector<VertexType> v_set = __vertex_array;
        int sum = v_set.size();
        std::vector<VertexType> u_set;
        u_set.reserve(__current_vertex);
        //设置初始节点
        u_set.push_back(__vertex_array[0]);
        v_set.erase(v_set.begin());
        int min_edge_value = __INIFNITE;
        int min_u_index = 0;
        int min_v_index = 0;
        int edge_value_get;
        while (u_set.size() != sum) {
            for (int i = 0; i < u_set.size(); ++i) {
                for (int j = 0; j < v_set.size(); ++j) {
                    edge_value_get = getEdge(u_set[i], v_set[j]);
                    if (edge_value_get < min_edge_value) {
                        min_u_index = i;
                        min_v_index = j;
                        min_edge_value = edge_value_get;
                    }
                }
            }

            smallest_tree.addEdge(std::make_tuple(u_set[min_u_index],
                                                  v_set[min_v_index],
                                                  min_edge_value));

            u_set.push_back(v_set[min_v_index]);
            v_set.erase(v_set.begin() + min_v_index);

            min_edge_value = __INIFNITE;
            min_u_index = 0;
            min_v_index = 0;
        }
        return smallest_tree;
    }

private:
    bool __checkIsLink(VertexType v1, VertexType v2) {

    }

    void __BFSMakeTree(int index_vertex,
                       std::vector<int> &traversed_arr,
                       Graph_undirect_net<VertexType> &g) {
        std::queue<int> q;
        q.push(index_vertex);
        traversed_arr.push_back(index_vertex);
        while (!q.empty()) {
            index_vertex = q.front();
            q.pop();
            std::vector<int> adjecent_vertex =
                    __get_adjacent_vertex_not_in_traversed_arr(index_vertex,
                                                               traversed_arr);
            if (adjecent_vertex.size() != 0)
                for (int i = 0; i < adjecent_vertex.size(); ++i) {
                    q.push(adjecent_vertex[i]);
                    traversed_arr.push_back(adjecent_vertex[i]);
                    g.addEdge(std::make_tuple(
                            __vertex_array[index_vertex],
                            __vertex_array[adjecent_vertex[i]],
                            getEdge(__vertex_array[index_vertex], __vertex_array[i])
                    ));
                }

        }

    }

    //real BFS
    void __BFS2_DEBUG(int index_vertex, std::vector<int> &traversed_arr) {
        std::queue<int> q;
        q.push(index_vertex);
        traversed_arr.push_back(index_vertex);
        while (!q.empty()) {
            index_vertex = q.front();
            q.pop();

            std::cout << __vertex_array[index_vertex] << " ";
            std::vector<int> adjecent_vertex =
                    __get_adjacent_vertex_not_in_traversed_arr(index_vertex,
                                                               traversed_arr);
            if (adjecent_vertex.size() != 0)
                for (int i = 0; i < adjecent_vertex.size(); ++i) {
                    q.push(adjecent_vertex[i]);
                    traversed_arr.push_back(adjecent_vertex[i]);
                }

        }
    }

    void __BFS2(int index_vertex, std::vector<int> &traversed_arr) {
        std::queue<int> q;
        q.push(index_vertex);
        while (!q.empty()) {
            index_vertex = q.front();
            q.pop();
            if (!std::count(traversed_arr.begin(),
                            traversed_arr.end(),
                            index_vertex)) {
                std::cout << __vertex_array[index_vertex] << " ";
                traversed_arr.push_back(index_vertex);
            }
            std::vector<int> adjecent_vertex =
                    __get_adjacent_vertex_not_in_traversed_arr(index_vertex,
                                                               traversed_arr);
            if (adjecent_vertex.size() != 0)
                for (int i = 0; i < adjecent_vertex.size(); ++i) {
                    q.push(adjecent_vertex[i]);
                }

        }
    }
    std::vector<int>
    __get_adjacent_vertex_not_in_traversed_arr(
            int index_vertex,
            std::vector<int> &traversed_arr) {
        //获得不在traversed_arr中的这个顶点的邻接点
        std::vector<int> adjacent_vertex;
        for (int i = 0; i < __current_vertex; ++i)
            if (__adjacency_matrix_graph[index_vertex][i] != __INIFNITE
                && std::count(traversed_arr.begin(),
                              traversed_arr.end(),
                              i) == 0) {
                adjacent_vertex.push_back(i);
            }
        return adjacent_vertex;
    }

    int __DFS(int index_vertex, std::vector<int> &traverse_arr) {
        if (!std::count(traverse_arr.begin(),
                        traverse_arr.end(),
                        index_vertex)) {
            std::cout << __vertex_array[index_vertex] << " ";
            traverse_arr.push_back(index_vertex);
            //获得这个顶点的邻接点
            std::vector<int> adjacent_vertex =
                    __get_adjacent_vertex_not_in_traversed_arr(index_vertex, traverse_arr);
            /* or
            std::vector<int> adjacent_vertex =
                      __get_adjacent_vertex(index_vertex);
            结果都一样，获得所有邻接顶点包括上一个遍历到的顶点或者其他路径遍历到的顶点
             ，但是函数开头进行了遍历过的顶点检查，所以不会发生重复情况
             使用获得没有遍历过的邻接顶点会快速一点
            */
            for (int i = 0; i < adjacent_vertex.size(); ++i)
                __DFS(adjacent_vertex[i], traverse_arr);
        }

    }

    std::vector<int> __get_adjacent_vertex(int index_vertex) {
        std::vector<int> adjacent_vertex;
        for (int i = 0; i < __current_vertex; ++i)
            if (__adjacency_matrix_graph[index_vertex][i] != __INIFNITE)
                adjacent_vertex.push_back(i);

        return adjacent_vertex;
    }

    int __getIndexOfVertex(VertexType vertex) {
        for (int i = 0; i < __current_vertex; ++i)
            if (__vertex_array[i] == vertex)
                return i;

        return -1;
    }
};
void test_undirect_graph(){
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
}

#endif //ALG_DATASRUCT_H
