#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    ll toSub = (n + 1) * n / 2;
    if (sum % toSub != 0) {
        puts("NO");
        return 0;
    }
    a.push_back(a[0]);
    ll k = sum / toSub;
    ll cumul = 0;
    rep(i, n) {
        ll diff = a[i + 1] - a[i];
        // diff = k - t * n
        diff = k - diff;
        if (diff < 0 || diff % n != 0) {
            puts("NO");
            return 0;
        }
        cumul += diff / n;
    }
    cout << (cumul == k ? "YES" : "NO") << endl;
}