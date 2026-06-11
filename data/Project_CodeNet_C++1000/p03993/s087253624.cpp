#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> a;
int main() {
    cin >> N;
    a.resize(N);
    rep(i, N) cin >> a[i];

    map<P, ll> mp;
    rep(i, N) {
        if (i + 1 > a[i]) {
            mp[P(a[i], i + 1)]++;
        } else {
            mp[P(i + 1, a[i])]++;
        }
    }

    ll ans = 0;
    for (auto v : mp) {
        if (v.second == 2) {
            ans++;
        }
    }
    cout << ans << endl;
}