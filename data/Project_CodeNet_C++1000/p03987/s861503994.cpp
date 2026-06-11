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

int h[maxn];

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
    }
    vector<int> prv(n);
    prv[0] = -1;
    for (int i = 1; i < n; ++i) {
        int cur = i - 1;
        while (cur != -1 && a[cur] > a[i]) {
            cur = prv[cur];
        }
        prv[i] = cur;
    }
    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        int cur = i + 1;
        while (cur != n && a[cur] > a[i]) {
            cur = nxt[cur];
        }
        nxt[i] = cur;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = prv[i];
        int r = nxt[i];
        ans += 1ll * a[i] * (i - l) * (r - i);
    }
    cout << ans;
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

