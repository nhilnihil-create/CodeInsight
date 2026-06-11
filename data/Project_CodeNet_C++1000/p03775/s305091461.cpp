#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;

ll n;
int B(ll x) {
    int c = 0;
    while (x) {
        x /= 10;
        ++c;
    }
    return c;
}
int main() {
    cin >> n;
    int ans = 1e9;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ll d = n / i;
            ans = min(ans, max(B(i),B(d)));
        }
    }
    cout << ans << endl;
    return 0;
}
