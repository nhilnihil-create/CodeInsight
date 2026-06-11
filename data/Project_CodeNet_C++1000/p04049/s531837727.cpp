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
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

class Tree {
    public:
    struct Node {
        std::vector<int> edge;
        int rank;
    };
    std::vector<Node> node;
    Tree() {}
    Tree(const int node_num_max) {
        node.resize(node_num_max);
    }
    void add_directed_edge(const int from, const int to) {
        node[from].edge.push_back(to);
    }
    void add_undirected_edge(const int node1, const int node2) {
        add_directed_edge(node1, node2);
        add_directed_edge(node2, node1);
    }
};

const int MAX_N = 2050;
int N, K, A[MAX_N], B[MAX_N];

Tree tree = Tree(MAX_N);

int R;
std::vector<int> far_node_num;

void set_rank(int n, int rank, int parent, int direction) {
    tree.node[n].rank = rank;

    if (rank == R + 1) {
        far_node_num[direction]++;
    }

    for (int c : tree.node[n].edge) {
        if (c != parent) {
            set_rank(c, rank + 1, n, direction);
        }
    }
}

int main(int argc, char **argv) {
    std::cin >> N >> K;

    for (int i = 1; i <= N - 1; i++) {
        std::cin >> A[i] >> B[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        tree.add_undirected_edge(A[i], B[i]);
    }

    R = K / 2;

    int tmp = 0;
    for (int i = 1; i <= N; i++) {
        far_node_num.clear();
        far_node_num.resize(tree.node[i].edge.size(), 0);

        tree.node[i].rank = 0;
        for (int c = 0; c < tree.node[i].edge.size(); c++) {
            set_rank(tree.node[i].edge[c], 1, i, c);
        }

        //int max = 0;
        //for (int num : far_node_num) {
        //    max = std::max(max, num);
        //}

        int near_num = 0;
        for (int j = 1; j <= N; j++) {
            if (tree.node[j].rank <= R) {
                near_num++;
            }
        }

        //std::cout << i << " " << near_num << std::endl;

        if (K % 2 == 1) {
            near_num += *std::max_element(far_node_num.begin(), far_node_num.end());
        }

        //std::cout << near_num << std::endl;

        tmp = std::max(tmp, near_num);
    }

    std::cout << N - tmp << std::endl;
    
    return 0;
}