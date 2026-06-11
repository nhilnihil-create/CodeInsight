#include <bits/stdc++.h>


using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-10;
const ll MOD = 998244353;
const ld PI = 3.141592653589793;
const int maxn = 300001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

struct pt {
    ld x, y;

    pt operator+(const pt &rhs) {
        return {x + rhs.x, y + rhs.y};
    }

    pt operator-(const pt &rhs) {
        return {x - rhs.x, y - rhs.y};
    }

    ld norm() {
        return hypotl(x, y);
    }

    pt operator*(ld v) {
        return {x * v, y * v};
    }
};

bool close_dbl(ld a, ld b) {
    return abs(a - b) < EPS;
}

bool less_dbl(ld a, ld b) {
    return a < b && !close_dbl(a, b);
}

bool less_equal_dbl(ld a, ld b) {
    return a < b || close_dbl(a, b);
}

int close_lg(int n) { return n > 1 ? 32 - __builtin_clz(n - 1) : 0; }

ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

ll mul(ll a, ll b, ll m) {
    return a * b % m;
}

ll pw(ll a, ll b, ll m) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = mul(res, a, m);
        }
        a = mul(a, a, m);
    }
    return res;
}

int cnt[1001];

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &el:a) {
        cin >> el;
        cnt[el]++;
    }
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    if ((mx + 1) / 2 > mn) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 0; i <= mx; ++i) {
        int cur_d = max(i, mx - i);
        if (!cnt[cur_d]) {
            cout << "Impossible";
            return 0;
        }
        --cnt[cur_d];
    }
    if (cnt[mn]) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible";
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

