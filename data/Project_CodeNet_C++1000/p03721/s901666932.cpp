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

    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    map<ll, ll> mp;
    rep(i, n) {
        if (mp.count(a[i]) == 0) {
            mp[a[i]] = b[i];
        } else {
            mp[a[i]] += b[i];
        }
    }

    vector<pair<ll, ll>> v;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        v.emplace_back(make_pair(itr->first, itr->second));
    }

    sort(v.begin(), v.end());

    ll cnt = 0;
    rep(i, v.size()) {
        cnt += v[i].second;

        if (cnt >= k) {
            cout << v[i].first << endl;
            break;
        }
    }
}