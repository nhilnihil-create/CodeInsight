#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <time.h>
#include <random>
#include <string>
#include <cassert>
#include <vector>
#include <ostream>
#include <istream>
#include <stack>
#include <deque>
#include <queue>
#include <functional>
#include <chrono>
#include <stack>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

ostream& operator<< (ostream &out, const vector<int> &b) {
    for (auto k : b) out << k << " ";
    return out;
}

istream& operator>> (istream& in, pii& b) {
    in >> b.first >> b.second;
    return in;
}

ostream& operator<< (ostream& out, const pii& b) {
    out << "{" << b.first << ", " << b.second << "}";
    return out;
}

template <typename T1, typename T2> inline bool chkmin(T1 &x, const T2 &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T1, typename T2> inline bool chkmax(T1 &x, const T2 &y) {if (x < y) {x = y; return 1;} return 0;}


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 10;
#else
    #define dbg(x) 57
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 179;
#endif

const ld PI = acos(-1);

#define time clock() / (double) CLOCKS_PER_SEC

// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,sse3,sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("avx2")  
// #pragma GCC optimize("section-anchors")
// #pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
// #pragma GCC optimize("vpt")
// #pragma GCC optimize("rename-registers")
// #pragma GCC optimize("move-loop-invariants")
// #pragma GCC optimize("unswitch-loops")
// #pragma GCC optimize("function-sections")
// #pragma GCC optimize("data-sections")

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 10;

int n;
int a[MAXN];
int t[4 * MAXN];

int merge(int x, int y) {
    if (a[x] < a[y]) return x;
    return y;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}

int ask(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl) return MAXN - 1;
    if (l >= askl && r <= askr) return t[v];
    int m = (l + r) / 2;
    return merge(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
}

int solve(int l, int r) {
    if (l >= r) return 0;
    int pos = ask(0, 0, n, l, r);
    return solve(l, pos) + solve(pos + 1, r) + a[pos] * (pos - l + 1) * (r - pos);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[MAXN - 1] = INF;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);
    cout << solve(0, n);
}
/*

*/