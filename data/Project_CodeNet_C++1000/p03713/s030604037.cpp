#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

ll check(ll x, ll y) {
    ll ans = LINF;
    if (x >= 3) {
        for (int i = 1; i <= x - 2; i++) {
            ll a = i * y;
            ll b = ((x - i) / 2) * y;
            ll c = ((x - i) - (x - i) / 2) * y;

            ll d = min(a, min(b, c));
            ll e = max(a, max(b, c));
            ans = min(ans, e - d);
        }
    }

    for (int i = 1; i <= x - 1; i++) {
        ll a = i * y;
        ll b = (x - i) * (y / 2);
        ll c = (x - i) * ( y - (y / 2));

        ll d = min(a, min(b, c));
        ll e = max(a, max(b, c));
        ans = min(ans, e - d);
    }

    return ans;
}

int main() {
    ll H, W;
    cin >> H >> W;

    cout << min(check(H, W), check(W, H)) << endl;
}