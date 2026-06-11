#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

void DFS(int vert, const vector<vector<int>>& edges, vector<pair<int, int>>& conectivity, bool roads, int con) {
    if (roads) {
        if (conectivity[vert].first == 0) {
            conectivity[vert].first = con;
            for (const auto & x: edges[vert]) {
                DFS(x, edges, conectivity, roads, con);
            }
        }
    } else {
        if (conectivity[vert].second == 0) {
            conectivity[vert].second = con;
            for (const auto & x: edges[vert]) {
                DFS(x, edges, conectivity, roads, con);
            }
        }
    }
}


int main() {
    int N, K, L;
    cin >> N >> K >> L;
    vector<vector<int>> roads(N);
    for (int i = 0; i < K; ++i) {
        int p, q;
        cin >> p >> q;
        roads[p - 1].push_back(q - 1);
        roads[q - 1].push_back(p - 1);
    }
    vector<vector<int>> railways(N);
    for (int i = 0; i < L; ++i) {
        int p, q;
        cin >> p >> q;
        railways[p - 1].push_back(q - 1);
        railways[q - 1].push_back(p - 1);
    }
    vector<pair<int, int>> conectivity(N);
    for (int i = 0; i < N; ++i) {
        DFS(i, roads, conectivity, 1, i + 1);
    }
    for (int i = 0; i < N; ++i) {
        DFS(i, railways, conectivity, 0, i + 1);
    }
   /* for (const auto & x: conectivity) {
        cout << x.first << " " <<x.second << '\n';
    } */
    vector<int> indexes(N);
    for (int i = 0; i < N; ++i) {
        indexes[i] = i;
    }
    vector<int> ans(N);
    sort(indexes.begin(), indexes.end(), [&conectivity](int a, int b) {return conectivity[a] < conectivity[b];});
    int i = 1;
    int cur_ans = 1;
    while (i < N) {
        while (i < N && conectivity[indexes[i]] == conectivity[indexes[i - 1]]) {
            ++i;
            ++ cur_ans;
        }
        if (i < N) {
            for (int k = i - 1; k >= i - cur_ans; --k) {
                ans[indexes[k]] = cur_ans;
            }
            cur_ans = 1;
            ++i;
        }
    }
    for (int k = i - 1; k >= i - cur_ans; --k) {
        ans[indexes[k]] = cur_ans;
    }
    for (const auto & x: ans) {
        cout << x << " ";
    }




    return 0;
}
