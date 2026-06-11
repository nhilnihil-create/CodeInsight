#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i, 0, n) cin >> t[i];

    ll ans = 1;
    rep(i, 0, n) {
        ans = lcm(ans, t[i]);
    }
    cout << ans << endl;
    return 0;
}
