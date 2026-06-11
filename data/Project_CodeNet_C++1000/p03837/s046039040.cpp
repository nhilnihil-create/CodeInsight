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
    int m;
    cin >> m;
    vector<int> A(m);
    vector<int> B(m);
    vector<int> C(m);

    const long long INF = 1LL << 50;
    vector<vector<long long>> dis(n, vector<long long>(n, INF));
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        --A[i], --B[i];
        dis[A[i]][B[i]] = C[i];
        dis[B[i]][A[i]] = C[i];
    }
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }


    int res = 0;
    for (int i = 0; i < m; ++i) {
        int u = A[i], v = B[i];
        bool ok = false;
        for (int s = 0; s < n && !ok; ++s) {
            for (int t = 0; t < n; ++t) {
                if (dis[s][u] + C[i] + dis[v][t] == dis[s][t]) {
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            ++res;
        }
    }

    cout << res << '\n';

    return 0;
}