#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll w, h;
    cin >> w >> h;

    vector<P> v;  // v[i] : (i番目に小さいコスト、横線なら1で縦線なら2)
    rep(i, w) {
        ll p;
        cin >> p;
        v.pb(make_pair(p, 1));
    }
    rep(i, h) {
        ll q;
        cin >> q;
        v.pb(make_pair(q, 2));
    }
    sort(all(v));

    ll tate = h+1;  // 縦線が何列あるか(最初はh+1列)
    ll yoko = w+1;  // 横線が何列あるか(最初はw+1列)
    ll ans = 0;
    rep(i, h+w) {
        if(v[i].second == 1) {  // 横線を使うとき
            ans += v[i].first*tate;
            yoko--;
        }
        else {  // 縦線を使うとき
            ans += v[i].first*yoko;
            tate--;
        }
    }

    out(ans);
    re0;
}