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

const int MAXN = 2001;
const int K = 13;

int n, x;
int a[MAXN], t[K][MAXN];
int pw[MAXN];

int ask(int l, int r) {
    int lg = pw[r - l + 1];
    return min(t[lg][l], t[lg][r - (1 << lg) + 1]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pw[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        pw[i] = pw[i / 2] + 1;
    }
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[0][i] = a[i];
    }
    for (int i = 1; i < K; i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    for (int l = 1; l < n; l++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (j < l) {
                cur += min(ask(n - (l - j), n - 1), ask(0, j));
            } else {
                cur += ask(j - l, j);
            }
        }
        chkmin(ans, cur + l * x);
    }
    cout << ans << "\n";
}
/*

*/