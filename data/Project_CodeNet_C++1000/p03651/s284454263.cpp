#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
ll gcd(ll a, ll b) {
    if (a < b) gcd(b, a);
    ll r = 1;
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll M = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    ll g = 0;
    g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    if (k >= g && k % g == 0 && k <= M) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
