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

class Union_Find {
    public:
    std::vector<int> par;
    Union_Find() {}
    Union_Find(int n){
        par.resize(n, 0);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    void simplify(int x) {
        std::vector<int> path;
        while (par[x] != x) {
            path.push_back(x);
            x = par[x];
        }
        for (int p : path) {
            par[p] = x;
        }
    }
    
    int find(int x){
        simplify(x);
        return par[x];
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y) {
            par[y] = x;
            // 改造する時は「根になっているノードの親を変更する」という原則が守られていることに注意。
        }
    }
};

struct Node {
    std::vector<int> edge;
    int color;
};

const int MAX_N = 100050;
const int MAX_M = 200050;

int N, M;
int u[MAX_M], v[MAX_M];

int num[MAX_N] = {};
Node graph[MAX_N];
Union_Find union_find = Union_Find(MAX_N);

bool is_bipertite(int n, int color) {
    if (graph[n].color == color) {
        return true;
    } else if (graph[n].color == -color) {
        return false;
    }

    graph[n].color = color;

    for (int e : graph[n].edge) {
        if (!is_bipertite(e, -color)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> u[i] >> v[i];
    }

    for (int i = 1; i <= M; i++) {
        union_find.unite(u[i], v[i]);
        graph[u[i]].edge.push_back(v[i]);
        graph[v[i]].edge.push_back(u[i]);
    }

    for (int i = 1; i <= N; i++) {
        num[union_find.find(i)]++;
        graph[i].color = 0;
    }

    long long single_num = 0;
    long long bipertite_num = 0;
    long long other_num = 0;

    for (int i = 1; i <= N; i++) {
        if (union_find.find(i) == i) {
            if (num[i] == 1) {
                single_num++;
            } else if (is_bipertite(i, 1)) {
                bipertite_num++;
            } else {
                other_num++;
            }
        }
    }

    //std::cout << single_num << " " << bipertite_num << " " << other_num << std::endl;

    long long ret = single_num * single_num + single_num * (N - single_num) * 2;
    ret += bipertite_num * bipertite_num * 2;
    ret += other_num * other_num + other_num * bipertite_num * 2;

    std::cout << ret << std::endl;

    return 0;
}
