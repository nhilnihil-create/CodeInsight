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

struct Node {
    int player;
    std::vector<int> children;
    int height;
    int rank;
};

const int MAX_N = 100050;
int N;
int a[MAX_N];

Node tree[MAX_N];

void dfs_set_rank(int node, int rank) {
    tree[node].rank = rank;

    for (auto c : tree[node].children) {
        dfs_set_rank(c, rank + 1);
    }
}

int main(int argc, char **argv) {
    std::cin >> N;

    a[1] = 0;
    for (int i = 2; i <= N; i++) {
        std::cin >> a[i];
    }

    for (int i = 2; i <= N; i++) {
        tree[a[i]].children.push_back(i);
    }

    dfs_set_rank(1, 0);

    std::vector<std::pair<int, int>> node_rank_vec;

    for (int i = 1; i <= N; i++) {
        node_rank_vec.push_back(std::pair<int, int>({i, tree[i].rank}));
    }

    std::sort(node_rank_vec.begin(), node_rank_vec.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; }
    );

    for (auto p : node_rank_vec) {
        int node = p.first;
        int tmp = 0;
        std::vector<int> child_height;
        for (int c : tree[node].children) {
            child_height.push_back(tree[c].height);
        }
        std::sort(child_height.begin(), child_height.end());
        for (int h : child_height) {
            tmp = std::max(tmp, h) + 1;
        }
        tree[node].height = tmp;

        //std::cout << "check:" << node << " " << tmp << std::endl;
    }

    std::cout << tree[1].height << std::endl;

    return 0;
}