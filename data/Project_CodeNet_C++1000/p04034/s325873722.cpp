#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m), y(m);
    rep(i, m) cin >> x.at(i) >> y.at(i);
    vector<ll> num(n, 1);
    vector<bool> red(n, false);
    red.at(0) = true;

    rep(i, m) {
        if(red[x[i] - 1])
            red[y[i] - 1] = true;

        num[x[i] - 1]--;
        num[y[i] - 1]++;

        if(num[x[i] - 1] == 0)
            red[x[i] - 1] = false;
    }

    ll ans = 0;
    rep(i, n) if(red[i]) ans++;
    cout << ans;
}