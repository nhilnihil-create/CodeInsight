//#pragma 03
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define eb emplace_back
#define ef emplace_front
#define rep(i, x, n) for (int i = x; i < n; ++i)
#define mp make_pair
#define fi first
#define se second
#define ii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vii vector<pair<int, int>>
#define reverse(s) reverse(s.begin(), s.end())
#define ld long double
#define vs vector<string>
#define inf INT_MAX
#define vc vector<char>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vb vector<bool>
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define ub(a, x) upper_bound(a.begin(), a.end(), x) 
#define vvi vector<vi>
#define mine(a) min_element(a.begin(),a.end())
#define maxe(a) max_element(a.begin(), a.end())
#define iota(a,i) iota(a.begin(),a.end(),i)
#define fileopen(filename) if (fopen(filename".INP", "r")) {freopen(filename".INP", "r", stdin);freopen(filename".OUT", "w", stdout);}
int n, root = 1;
vi a;
vvi adj;
void dfs(int x, int p) {
    if (adj[x].size() == 1) return;
    int sum = 0;
    for (int i : adj[x]) {
        if (i != p) {
            dfs(i, x);
            sum += a[i];
            if (a[i] > a[x]) {
                cout << "NO";
                exit(0);
            }
        }
    }
    int u = sum - a[x], v = a[x] - u;
    if (u < 0 || v < 0) {
        cout << "NO";
        exit(0);
    }
    a[x] = v;
}
signed main() {
    fastio;
    cin >> n;
    a.resize(n + 1);
    adj.resize(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    if (n == 2) {
        if (a[1] == a[2]) cout << "YES";
        else cout << "NO";
        return 0;
    }
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        if (root == 1) {
            if (adj[x].size() > 1) root = x;
            if (adj[y].size() > 1) root = y;
        }
    }
    dfs(root, root);
    if (a[root]) cout << "NO";
    else cout << "YES";
}