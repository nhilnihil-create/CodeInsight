#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define x first
#define y second
#define int long long
#define double long double
#define pii pair<int, int>
#define pb push_back
#define vec vector
#define beg begin
#define dbg(x) cerr << #x << " = " << x << endl;

template<class T> ostream& operator<<(ostream &str, vector<T> &a) {
    for (auto &i : a) {
        str << i << " ";
    }
    return str;
}

template<class T> istream& operator>>(istream &str, vector<T> &a) {
    for (auto &i : a) {
        str >> i;
    }
    return str;
}

template<class T> ostream& operator<<(ostream &str, pair<T, T> &a) {
    str << a.first << " " << a.second;
    return str;
}

template<class T> istream& operator>>(istream &str, pair<T, T> &a) {
    str >> a.first >> a.second;
    return str;
}

void solve(); signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\artma\\CLionProjects\\problems\\input.txt", "r", stdin);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(6);
    solve();
    return 0;
}

const int MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e18 + 10, BASE = 37;
int T = 0;
vec<int> comp;

void dfs(int v, vec<int> &used, vec<int> &group, vec<vec<int>> &g) {
    used[v] = 1;
    group[v] = T;
    comp.pb(v);
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u, used, group, g);
        }
    }
}

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vec<vec<int>> g1(n + 1), g2(n + 1);
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        g1[u].pb(v);
        g1[v].pb(u);
    }
    for (int i = 0; i < l; ++i) {
        int u, v;
        cin >> u >> v;
        g2[u].pb(v);
        g2[v].pb(u);
    }

    vec<int> group1(n + 1), group2(n + 1), used1(n + 1), used2(n + 1);
    vec<vec<int>> gs;

    T = 1;
    for (int v = 1; v <= n; ++v) {
        if (!used1[v]) {
            comp.clear();
            dfs(v, used1, group1, g1);
            T++;
            gs.pb(comp);
        }
    }
    T = 1;
    for (int v = 1; v <= n; ++v) {
        if (!used2[v]) {
            comp.clear();
            dfs(v, used2, group2, g2);
            T++;
        }
    }

    vec<int> ans(n + 1);
    for (auto it : gs) {
        map<int, vec<int>> mp;
        for (auto el : it) {
            mp[group2[el]].pb(el);
        }
        for (auto it : mp) {
            for (auto el : it.y) {
                ans[el] = sz(it.y);
            }
        }
    }

    for (int v = 1; v <= n; ++v) {
        cout << ans[v] << " ";
    }
    cout << endl;
}