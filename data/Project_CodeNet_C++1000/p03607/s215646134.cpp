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

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    rep(i, n) {
        if (mp.count(a[i])) {
            mp[a[i]]++;
        } else {
            mp[a[i]] = 1LL;
        }
    }

    ll cnt = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second%2){
            cnt++;
        }
    }

    cout << cnt << endl;
}