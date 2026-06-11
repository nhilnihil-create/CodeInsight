#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll n;
    cin >> n;

    vec<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll ans0 = 0;
    ll sm   = 0;
    rep(i, n) {
        sm += a[i];
        if (i % 2 == 0 && sm <= 0) {
            ans0 += (abs(sm) + 1);
            sm = 1;
        } else if (i % 2 == 1 && sm >= 0) {
            ans0 += (abs(sm) + 1);
            sm = -1;
        }
    }

    ll ans1 = 0;
    ll sm1  = 0;
    rep(i, n) {
        sm1 += a[i];
        if (i % 2 == 0 && sm1 >= 0) {
            ans1 += (abs(sm1) + 1);
            sm1 = -1;
        } else if (i % 2 == 1 && sm1 <= 0) {
            ans1 += (abs(sm1) + 1);
            sm1 = 1;
        }
    }
    cout << min(ans0, ans1) << endl;
}
