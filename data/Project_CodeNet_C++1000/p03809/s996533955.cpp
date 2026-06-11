
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <chrono>
#include <ctime>
#include <queue>
#include <math.h>
#include <deque>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <stdio.h>
#include <cstring>
#include <random>

using namespace std;
#define int long long
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define try tr
#define pii pair<int, int>
#define ti tuple <int, int, int>
#define vi vector <int>
#define vpi vector <pii>
#define umap unordered_map
#define uset unordered_set
#define left left11
#define right right11
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define sqr(a) ((a) * (a))
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fs first
#define sc second

ld TL = 0.25;
bool is_tl = 0;
int CALLS = 0;

inline bool IS() {
    if (++CALLS == 1000) {
        CALLS = 0;
        is_tl |= clock() > (TL - 0.1) * CLOCKS_PER_SEC;
    }
    return is_tl;
}

template<typename T1, typename T2>
inline void amin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void amax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
    os << p.first << ' ' << p.second << endl;
    return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    for (auto &u : v) os << u << ' ';
    os << endl;
    return os;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 1e6 + 7, NS = 2e3 + 7, lg = 19, sq = 550, inf = 1e18 + 7, SM = 1e2 + 7;
const ld eps = 1e-9;
int hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937}, mod = hash_mod[rnd() % 4];
int hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
vi v[N];
int c[N];
void dfs(int x, int p) {
    if(v[x].size() == 1)
        return;
    int sum = 0;
    for (auto u : v[x]) {
        if(u == p) continue;
        dfs(u, x);
        sum += c[u];
    }
    int up = 2 * c[x] - sum, down = sum - c[x];
    for (auto u : v[x]) {
        if(u == p) continue;
        if(c[u] - up > 2 * down - (c[u] - up)) {
            cout << "NO";
            exit(0);
        }
    }
    if(up < 0 || down < 0) {
        cout << "NO";
        exit(0);
    }
    c[x] = up;
    //cout << x + 1 << ' ' << c[x] << endl;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    if(n == 2) {
        if(c[0] == c[1])
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    int root = 0;
    for (int i = 0; i < n ;i++) {
        if(v[i].size() > 1) {
            root = i;
            break;
        }
    }
    dfs(root, -1);
    if(c[root] == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    fast
    solve();
}
