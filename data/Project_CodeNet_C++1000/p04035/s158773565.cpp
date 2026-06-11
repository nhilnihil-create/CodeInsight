#include <bits/stdc++.h>


using namespace std;


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-10;
const ll MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 200001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[maxn];

signed main() {
#ifdef zxc
    mt19937 mt(228);
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
//            freopen("", "r", stdin);
//        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(10);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    int n;
    cin >> n;
    int l;
    cin >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int pos = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i + 1] >= l) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (int i = 1; i < pos; ++i) {
        cout << i << "\n";
    }
    for (int i = n - 1; i >= pos; --i) {
        cout << i << "\n";
    }
    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

