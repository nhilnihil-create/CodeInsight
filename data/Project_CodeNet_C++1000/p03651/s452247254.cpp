#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    ll M = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > M) M = a[i];
    }
    ll g = a[1];
    for (int i = 2; i <= n; i++) {
        g = gcd(g, a[i]);
    }
    if ((k % g)||(k > M)) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << "POSSIBLE" << endl;
    }
    return 0;
}