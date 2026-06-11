//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

ll n;
vector<ll> a(100100), b(100100);

ll dif(ll x, ll m) {
    ll y = (x+m-1)/m*m;//x以上の最小のmの倍数
    return y-x;
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    rep(i, n) cin >> a[i] >> b[i];
    reverse(all(a));
    reverse(all(b));
    ll cnt = 0;
    rep(i, n) {
        a[i] += cnt;
        cnt += dif(a[i], b[i]);
    }
    cout << cnt << endl;

    return 0;
}