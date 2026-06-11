#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
using matrix = vector<vector<uint>>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acos(-1);

vector<int> dp;
int dfs(int v, int p, Graph<int> &G) {
    for (auto nv : G[v]) {
        if (nv == p)
            continue;
        dp[v] ^= dfs(nv, v, G) + 1;
    }
    return dp[v];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    Graph<int> G(N);
    for (int i = 1; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp.resize(N);
    dfs(0, -1, G);

    cout << (dp[0] ? "Alice" : "Bob") << endl;
    return 0;
}
