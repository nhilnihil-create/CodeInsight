#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<bool> used(n);
    vector<vector<int> > graph(n);
    int s, t;
    rep (i, m) {
        int a, b; cin >> a >> b; a--; b--;
        if (i == 0) {s = a; t = b;}
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    used[s] = used[t] = true;
    vector<int> ss{s}, tt{t};
    int now = s;
    while (true) {
        if (all_of(all(graph[now]), [&](int x){return used[x];})) break;
        for (int i : graph[now]) {
            if (!used[i]) {
                ss.push_back(i); now = i; used[now] = true;
                break;
            }
        }
    }
    now = t;
    while (true) {
        if (all_of(all(graph[now]), [&](int x){return used[x];})) break;
        for (int i : graph[now]) {
            if (!used[i]) {
                tt.push_back(i); now = i; used[now] = true;
                break;
            }
        }
    }
    reverse(all(ss));
    cout << ss.size() + tt.size() << '\n';
    for (int i : ss) cout << i + 1 << ' ';
    for (int i : tt) cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}