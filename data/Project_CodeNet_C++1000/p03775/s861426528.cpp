#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    auto res = divisor(n);
    sort(res.begin(), res.end());
    ll ans = 1e10;
    for (auto r : res) {
        ll a = to_string(r).size();
        ll b = to_string(n / r).size();
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;

    return 0;
}
