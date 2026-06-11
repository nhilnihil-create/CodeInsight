#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, x;
    cin >> n >> x;

    // the first 2 step always results in travel by n
    ll ans = n;
    // the initial parallelogram
    ll a = max(n - x, x), b = min(n - x, x);

    // Euclidean Algorithm
    while (b) {
        // # of times to reflect by 2*b
        ll q = a / b;
        ll r = a % b;

        ans += (b * 2) * q;
        // the last would be the diagonal
        if (r == 0) ans -= b;

        a = b, b = r;
    }
    cout << ans << endl;
}