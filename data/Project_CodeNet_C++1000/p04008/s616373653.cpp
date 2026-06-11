#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

const int N = 123456;
int n, b, ans;
int p[N];
V<int> g[N];

int dfs(int v) {
    int ma = 0;
    for (int u: g[v]) {
        int d = dfs(u) + 1;
        if (d == b) {
            ans++;
        } else {
            ma = max(ma, d);
        }
    }
    return ma;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
        if (i) g[p[i]].push_back(i);
    }
    ans += (p[0] != 0);
    for (int u: g[0]) dfs(u);
    cout << ans << endl;
    return 0;
}