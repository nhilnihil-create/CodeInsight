#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    ll ans = 1e18;
    ll s = 0;
    for (int i = 0; i < n-1; i++) {
        s += v[i];
        ans = min(ans, abs(s - (sum - s)));
    }

    cout << ans << endl;

    return 0;
}