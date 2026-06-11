#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    bool ok = true;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    ok = false;
                }
            }
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    long long res = 0;

    vector<vector<bool>> used(n, vector<bool>(n, false));

    using PIII = pair<int, pair<int,int>>;
    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
           pq.emplace(A[i][j], make_pair(i, j)); 
        }
    }

    while (!pq.empty()) {
        int d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (used[x][y]) {
            continue;
        }
        res += d;

        for (auto v : {x, y}) {
            int w = x + y - v;
            for (int i = 0; i < n; ++i) {
                if (v == i) {
                    continue;
                }
                if (i < v) {
                    if (A[i][v] == A[i][w] + d) {
                        used[i][v] = true;
                    }
                } else {
                    if (A[v][i] == d + A[i][w]) {
                        used[v][i] = true;
                    }
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}