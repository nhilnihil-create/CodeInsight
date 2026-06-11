#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll x = a[0].first, y = a[0].second;
    for (int i = 1; i < n; i++) {
        ll n = max((x + a[i].first - 1LL) / a[i].first, (y + a[i].second - 1LL) / a[i].second);
        x = a[i].first * n;
        y = a[i].second * n;
    }
    cout << x + y << '\n';
}