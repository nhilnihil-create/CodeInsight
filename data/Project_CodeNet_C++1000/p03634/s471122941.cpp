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
    vector<vector<pair<int,int>>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int q, K;
    cin >> q >> K;
    --K;
    int rt = K;

    vector<long long> dis(n, 0);
    vector<int> que;
    que.push_back(rt);
    vector<int> pars(n, -1);
    for (int i = 0; i < que.size(); ++i) {
        int u = que[i];
        for (auto& e : graph[u]) {
            int v = e.first;
            if (v == pars[u]) {
                continue;
            }
            pars[v] = u;
            dis[v] = dis[u] + e.second;
            que.push_back(v);
        }
    }

    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        long long d = dis[u] + dis[v];
        cout << d << '\n';
    }

    return 0;
}