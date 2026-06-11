//
// Created by Ильдар Ялалов on 14.01.2020.
//
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double dbl;
typedef unsigned int uint;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define mp make_pair
#define all(a) a.begin(),a.end()


#ifdef zxc

#include "debug.h"

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

bool debug = 0;
const int MAXN = (1e6) + 100;
const int LOG = 21;
const int mod = 1e9 + 7;
const int MX = (3e7 + 100);


void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        sum = sum % 2;
    }
    if (sum == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES ( n==1)
signed main() {

#ifdef zxc
    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#else
#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(15);


    int t = 1;
    while (t--) {
        solve();
    }
    debug(1.0 * clock() / CLOCKS_PER_SEC);
}
