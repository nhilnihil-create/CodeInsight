#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, X;
    cin >> N >> X;
    vector<ll> a(N);
    vector<ll> Xs;
    rep(i, N) { cin >> a[i]; }
    ll ans = 0;

    rep(i, N - 1) {
        ll x = X;
        ll p1 = a[i], p2 = a[i + 1];
        if (p1 + p2 > x) {
            ll diff = p1 + p2 - x;
            a[i + 1] = max((ll)0, p2 - diff);
            ans += min(p2, diff);
            diff -= ans;
            Xs.push_back(diff);
        } else {
            Xs.push_back(0);
        }
    }

    rep(i, N - 1) {
        ll x = Xs[i];
        ll p1 = a[i], p2 = a[i + 1];
        if (x <= 0)
            continue;
        else {
            ans += min(p1, x);
        }
    }

    cout << ans << endl;
}