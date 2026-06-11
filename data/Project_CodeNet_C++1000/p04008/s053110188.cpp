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
        int direction;
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
    void set_rank(int n, int rank, int parent) { // 辺が有向でも無向でも使える。呼び出すとき、parentは-1にしておくとよい。
        node[n].rank = rank;
        for (int c : node[n].edge) {
            if (c != parent) {
                set_rank(c, rank + 1, n);
            }
        }
    }
};
 
const int MAX_SIZE = 100050;
int N, K, a[MAX_SIZE];
Tree tree = Tree(MAX_SIZE);
bool is_checked[MAX_SIZE];
 
void set_checked(int n) {
    if (is_checked[n]) {
        return;
    }
    is_checked[n] = true;
    for (int c : tree.node[n].edge) {
        set_checked(c);
    }
}
 
int main(int argc, char **argv) {
    std::cin >> N >> K;
 
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }
 
    int ret = 0;
 
    if (K == 1) {
        for (int i = 1; i <= N; i++) {
            if (a[i] != 1) {
                ret++;
            }
        }
        std::cout << ret << std::endl;
        return 0;
    }
 
    if (a[1] != 1) {
        a[1] = 1;
        ret++;
    }
    is_checked[1] = true;
 
    for (int i = 2; i <= N; i++) {
        tree.add_directed_edge(a[i], i);
        is_checked[i] = false;
    }
 
    tree.set_rank(1, 0, -1);
 
    std::vector<std::pair<int, int>> node_rank;
    for (int i = 2; i <= N; i++) {
        node_rank.push_back(std::pair<int, int>({i, tree.node[i].rank}));
    }
    std::sort(node_rank.begin(), node_rank.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; }
    );
 
    for (auto pair : node_rank) {
        int i = pair.first;
        if (is_checked[i]) {
            continue;
        }
        if (pair.second <= K) {
            break;
        }
        int num = 0;
        while (true) {
            i = a[i];
            num++;
            if (num == K - 1) {
                break;
            }
        }
        a[i] = 1;
        ret++;
        set_checked(i);
    }
 
    std::cout << ret << std::endl;
 
    return 0;
}