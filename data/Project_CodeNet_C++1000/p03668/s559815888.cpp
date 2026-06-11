#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll SIZE = 1e5 + 10, INF = 1e9, K = 300;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<ll>> g;

bool used[SIZE];

ll dfs(int v) {
    used[v] = 1;

    ll cur = 0;
    for (auto to : g[v]) {
        if (!used[to]) {
            
            cur ^= (dfs(to) + 1);
        }
    }

    return cur;
}
int main() {
    fastInp;

    ll n;
    cin >> n;

    g.resize(n);

    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    if (dfs(0)) {
        cout << "Alice";
    }
    else {
        cout << "Bob";
    }
    return 0;
}