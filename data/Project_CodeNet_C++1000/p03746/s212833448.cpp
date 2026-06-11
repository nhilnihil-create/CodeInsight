#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

class Direct_Graph {
    public:
    struct Edge { 
        int to; long long cost;
    };
    std::vector<std::vector<Edge>> G;
    int node_num;
    Direct_Graph() {}
    Direct_Graph(const int node_num_in) {
        node_num = node_num_in;
        G.resize(node_num);
    }
    void add_edge(const int from, const int to, const long long cost) {
        Edge edge; edge.to = to; edge.cost = cost;
        G[from].push_back(edge);
    }
    void add_edge_both(const int node1, const int node2, const long long cost) {
        add_edge(node1, node2, cost);
        add_edge(node2, node1, cost);
    }
};

const int MAX_N = 200050;
const int MAX_M = 100050;

int N, M;
int A[MAX_M], B[MAX_M];

Direct_Graph dg = Direct_Graph(MAX_N);
std::set<int> used;

void dfs(int n, std::vector<int>& path) {
    path.push_back(n);
    used.insert(n);
    for (auto edge : dg.G[n]) {
        if (used.find(edge.to) == used.end()) {
            dfs(edge.to, path);
            break;
        }
    }
}

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> A[i] >> B[i];
    }

    for (int i = 1; i <= M; i++) {
        dg.add_edge_both(A[i], B[i], 1);
    }

    std::vector<int> path1, path2;
    used.insert(A[1]);
    used.insert(B[1]);

    dfs(A[1], path1);
    dfs(B[1], path2);

    std::cout << path1.size() + path2.size() << std::endl;

    for (int i = path1.size() - 1; 0 <= i; i--) {
        std::cout << path1[i] << " ";
    }
    for (int i = 0; i < path2.size(); i++) {
        std::cout << path2[i] << " ";
    }

    return 0;
}
