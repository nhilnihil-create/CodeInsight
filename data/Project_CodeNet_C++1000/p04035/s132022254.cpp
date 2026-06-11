#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n - 1) {
        if (a[i] + a[i + 1] >= l) {
            puts("Possible");
            for (int j = 1; j <= i; j++) {
                cout << j << endl;
            }
            for (int j = n - 1; j > i; j--) {
                cout << j << endl;
            }
            return 0;
        }
    }
    puts("Impossible");
}