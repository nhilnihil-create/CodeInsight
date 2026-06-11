#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)
typedef long long ll;

const int N = 500505;
const int mod = 1e9 + 7;

int n, a[N], u, v;
vector<int> g[N];
inline void no() {
    cout << "NO";
    exit(0);
}

inline ll dfs(int v, int p = 0) {
    vector<ll> h;
    for(int to : g[v]) {
        if(to == p) continue;
        h.pb(dfs(to, v));
    }
    if(!h.size()) return a[v];
    ll sum = 0;
    for(ll w : h) sum += w;
    ll min_moves = sum / 2;
    ll max_moves = sum;
    if(a[v] < min_moves || a[v] > max_moves)
        no();
    ll moves_by_two = max_moves - a[v];
    ll all_moves = min(sum - *max_element(h.begin(), h.end()), sum / 2);
    if(moves_by_two > all_moves) no();
    sum -= moves_by_two * 2;
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fo(i, n) cin >> a[i];
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    if(n == 2) {
        if(a[1] == a[2]) return cout << "YES", 0;
        cout << "NO";
        return 0;
    }
    int root = 1;
    for(int i = 1; i <= n; ++i)
        if(g[i].size() != 1) root = i, i = n + 1;
    if(dfs(root) != 0) return cout << "NO", 0;
    cout << "YES";
    return 0;

}