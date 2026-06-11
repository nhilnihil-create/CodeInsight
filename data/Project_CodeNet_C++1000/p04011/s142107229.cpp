#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ll n, k, x, y; cin >> n >> k >> x >> y;
    ll m = min(n, k);
    ll ans = m * x;
    n -= m;
    ans += (n * y);
    cout << ans << endl;
}