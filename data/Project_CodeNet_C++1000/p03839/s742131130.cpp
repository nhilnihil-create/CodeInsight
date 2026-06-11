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
using ld = long double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 600001;
const ll MOD = 1e9 + 7;
using cd = complex<double>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

bool close_dbl(ld a, ld b) {
    return abs(a - b) < EPS;
}

struct pt {
    ll x, y, z;
};

pt operator-(const pt &fi, const pt &se) {
    return {fi.x - se.x, fi.y - se.y, fi.z - se.z};
}

pt cross(const pt &fi, const pt &se) {
    return {fi.y * se.z - fi.z * se.y, -(fi.x * se.z - fi.z * se.x), fi.y * se.z - fi.z * se.y};
}

int dumb(vector<pt> pts) {
    int n = pts.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int e = i + 1; e < n; ++e) {
            pt cock = pts[e] - pts[i];
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                auto vv = cross(cock, pts[j] - pts[i]);
                cur += (vv.x == 0) && (vv.y == 0) && (vv.z == 0);
            }
            ans = max(ans, cur);
        }
    }
    return ans;
}

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

//    auto solve = [](int _) {
//        int n;
//        cin >> n;
//        int ans = min(n, 2);
//        vector<pt> pts(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> pts[i].x >> pts[i].y >> pts[i].z;
//        }
//        for (int i = 0; i < n; ++i) {
//            vector<int> p(n);
//            iota(p.begin(), p.end(), 0);
//            p.erase(p.begin() + i);
//            vector<ld> ang(n);
//            for (int j = 0; j < n; ++j) {
//                if (j == i) {
//                    continue;
//                }
//                ang[j] = atan2(pts[j].y - pts[i].y, pts[j].x - pts[i].x);
//            }
//            sort(p.begin(), p.end(), [&](int i, int j) {
//                return ang[i] < ang[j];
//            });
//            for (int j = 0, e = 0; e < p.size(); e = j) {
//                vector<ld> vals;
//                while (j < p.size() && close_dbl(ang[p[j]], ang[p[e]])) {
//                    vals.push_back(atan2(pts[p[j]].z - pts[i].z, pts[p[j]].x - pts[i].x));
//                    ++j;
//                }
//                sort(vals.begin(), vals.end());
//                int cur = 2;
//                ld was = vals[0];
//                for (int i = 1; i < vals.size(); ++i) {
//                    if (close_dbl(was, vals[i])) {
//                        ++cur;
//                        ans = max(ans, cur);
//                    } else {
//                        cur = 2;
//                        was = vals[i];
//                    }
//                }
//            }
//        }
//
//        cout << ans;
//    };




    auto solve = [](int _) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<ll> pref_pos(n + 1);
        vector<ll> suff_pos(n + 2);
        for (int i = 1; i <= n; ++i) {
            pref_pos[i] = pref_pos[i - 1];
            if (a[i] > 0) {
                pref_pos[i] += a[i];
            }
        }
        for (int i = n; i >= 1; --i) {
            suff_pos[i] = suff_pos[i + 1];
            if (a[i] > 0) {
                suff_pos[i] += a[i];
            }
        }
        vector<ll> pref(n + 1);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] + a[i];
        }
        ll ans = 0;
        for (int i = 1; i + k - 1 <= n; ++i) {
            ll cur = pref[i + k - 1] - pref[i - 1];
            ans = max(ans, max<ll>(cur, 0ll) + pref_pos[i - 1] + suff_pos[i + k]);
        }
        cout << ans;
    };


    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    solve(1);
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}
