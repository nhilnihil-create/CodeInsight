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

void out(vector<int> a, vector<int> b) {
    cout << a << "\n" << b.size() << "\n" << b << "\n";
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] & 1);
    }
    if (cnt > 2) {
        cout << "Impossible\n";
        return 0;
    }
    if (n == 1) {
        if (a[0] == 1) {
            out(a, {1});
        } else  {
            out(a, {a[0] - 1, 1});
        }
        return 0;
    }
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            if (f) {
                swap(a[i], a[n - 1]);
                break;
            } else {
                swap(a[i], a[0]);
                f = 1;
            }
        }
    }
    vector<int> b;
    if (a[0] & 1) {
        if (a[0] == 1) {
            b.pb(2);
        } else {
            b.pb(a[0] - 1);
            b.pb(2);
        }
    } else {
        b.pb(a[0] + 1);
    }
    for (int i = 1; i < n - 1; i++) {
        b.pb(a[i]);
    }
    int s = 0;
    for (auto k : b) {
        s += k;
    }
    if (m - s > 0) {
        b.pb(m - s);
    }
    out(a, b);
}
/*

*/