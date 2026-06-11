#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ll a[7];
    rep(i, 7) cin >> a[i];
    ll a0 = a[1], a1 = a[1];
    ll x = min(a[0], min(a[3], a[4]));
    a0 += x * 3;
    a0 += (a[0] - x) / 2 * 2;
    a0 += (a[3] - x) / 2 * 2;
    a0 += (a[4] - x) / 2 * 2;
    if (x > 0) {
        x--;
        a1 += x * 3;
        a1 += (a[0] - x) / 2 * 2;
        a1 += (a[3] - x) / 2 * 2;
        a1 += (a[4] - x) / 2 * 2;
    }
    cout << max(a0, a1) << endl;
}