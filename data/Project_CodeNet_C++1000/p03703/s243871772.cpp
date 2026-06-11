#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"
#include "profile.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define profile(X) LOG_DURATION(X)
#else
#define debug(...) 42
#define profile(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 600001;
using cd = complex<double>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

struct fenwick {
    fenwick(int size) : data(size) {

    }

    void add(int pos, int val) {
        for (; pos < data.size(); pos |= pos + 1) {
            data[pos] += val;
        }
    }

    ll get(int pos) {
        ll res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            res += data[pos];
        }
        return res;
    }

    vector<int> data;

};

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    profile("all");
    auto solve = [](int _) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> a(n + 1);
        vector<ll> pref(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] -= k;
            pref[i] = pref[i - 1] + a[i];
        }
        vector<int> p(n + 1);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return tie(pref[i], i) < tie(pref[j], j);
        });
        ll ans = 0;
        fenwick fwt(n + 1);
        for (int i:p) {
            ans += fwt.get(i - 1);
            fwt.add(i, 1);
        }
        cout << ans;
    };


    fast_io();

    cout.precision(9);
    cout <<
         fixed;
    for (int i = 1; i <= 1; ++i)
        solve(1);


}
