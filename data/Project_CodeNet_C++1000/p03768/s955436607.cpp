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
    int color;
    std::vector<int> neighbor;
    int lock_dist;
};

const int MAX_N = 100050;
int N, M, Q;
int a[MAX_N], b[MAX_N], v[MAX_N], d[MAX_N], c[MAX_N];

Node graph[MAX_N];

void dfs(int node, int color, int dist) {
    if (graph[node].color == 0) {
        graph[node].color = color;
    }

    if (dist <= graph[node].lock_dist) {
        return;
    }

    graph[node].lock_dist = dist;

    for (auto n : graph[node].neighbor) {
        dfs(n, color, dist - 1);
    }
}

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::cin >> Q;

    for (int i = 1; i <= Q; i++) {
        std::cin >> v[i] >> d[i] >> c[i];
    }

    for (int i = 1; i <= N; i++) {
        graph[i].color = 0;
        graph[i].lock_dist = 0;
    }

    for (int i = 1; i <= M; i++) {
        graph[a[i]].neighbor.push_back(b[i]);
        graph[b[i]].neighbor.push_back(a[i]);
    }

    for (int i = Q; 1 <= i; i--) {
        dfs(v[i], c[i], d[i]);
    }

    for (int i = 1; i <= N; i++) {
        std::cout << graph[i].color << std::endl;
    }

    return 0;
}
