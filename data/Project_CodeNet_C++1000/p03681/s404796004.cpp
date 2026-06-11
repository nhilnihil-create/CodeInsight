#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    if (m > n) {
        ll t = m;
        m = n;
        n = t;
    }

    ll cnt = 1;

    if (n - m > 1) {
        cout << 0 << endl;
    } else if ((n - m) == 1) {
        for (ll i = n; i >= 1; i--) {
            cnt *= i;
            cnt %= mod;
        }
        for (ll i = m; i >= 1; i--) {
            cnt *= i;
            cnt %= mod;
        }
        cout << cnt << endl;
    } else if ((n - m) == 0) {
        for (ll i = n; i >= 1; i--) {
            cnt *= i;
            cnt %= mod;
        }
        for (ll i = m; i >= 1; i--) {
            cnt *= i;
            cnt %= mod;
        }
        cnt *= 2;
        cnt %= mod;

        cout << cnt << endl;
    }
}