#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 300001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

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
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s.size() + t.size() < n) {
        cout << s << string(n - t.size() - s.size(), 'a') << t << "\n";
        return 0;
    }
    int mx_inter = 0;
    for (int inter = 1; inter <= s.size() + t.size() - n && inter <= s.size() && inter <= t.size(); ++inter) {

        if (s.substr(s.size() - inter) == t.substr(0, inter)) {
            mx_inter = inter;
        }
    }
    cout << s.size() + t.size() - mx_inter << "\n";
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

