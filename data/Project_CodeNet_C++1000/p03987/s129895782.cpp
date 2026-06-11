#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vi a(n);
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]] = i;
    }

    ll ans = 0;
    set<int> s = {-1, n};
    rep(i, n) {
        auto itr = s.lower_bound(m[i + 1]);
        ll r = *itr;
        itr--;
        ll l = *itr;
        // cout << i << " " << l << " " << m[i + 1] <<" " << r << endl;
        ans += (ll)(i + 1) * (m[i + 1] - l) * (r - m[i + 1]);
        s.insert(m[i + 1]);
    }

    cout << ans << endl;
    return 0;
}