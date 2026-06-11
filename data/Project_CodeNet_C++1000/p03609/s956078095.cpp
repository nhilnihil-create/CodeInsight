#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n+m; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    ll X, t;
    cin >> X >> t;
    if (X - t < 0) {
        cout << 0 << endl;
    } else {
        cout << X - t << endl;
    }
    return 0;
}
