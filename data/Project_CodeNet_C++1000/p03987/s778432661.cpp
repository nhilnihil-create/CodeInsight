#ifdef ABACABA

#include "stdc++.h"

#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define int long long

typedef long double ld;

#define all(a) a.begin(), a.end()

#define pii pair<int, int>

#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>

#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mkt make_tuple
#define ff first
#define ss second

#define in(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 1000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    vi b(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]] = i;
    }

    set<int> id;

    id.insert(-1);
    id.insert(n);

    int sum = 0;

    for (int j = 1; j <= n; ++j) {
        int x = b[j];

        int l = *prev(id.ub(x), 1);
        int r = *(id.ub(x));

        ++l;
        --r;

        sum += (x - l + 1) * (r - x + 1) * j;

        id.insert(x);
    }

    cout << sum;
    // 0 1[2 3]4 5 6 7 8
    // 7 - 8 3 - 9 4 6 5
}