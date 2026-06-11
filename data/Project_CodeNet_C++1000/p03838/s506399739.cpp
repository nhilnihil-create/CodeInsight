#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rnr(i, a, b) for(ll i = ll(a); i >= ll(b); i--)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

ll orimin(ll x, ll y) {
    if(x < 0) x = LLINF;
    if(y < 0) y = LLINF;
    return min(x, y);
}

int main() {
    /*
    int n, m; cin >> n >> m;
    int x[n]; rep(i, n) cin >> x[i];
    */
    ll x, y; cin >> x >> y;
    ll ans = LLINF + 10;
    rep(i, 2) {
        rep(j, 2) {
            ll tmpx = x, tmpy = y, tmpans = 0;
            if(i) tmpx = -tmpx, ++tmpans;
            tmpans += orimin((tmpy - tmpx), (-tmpy - tmpx));
            tmpx += orimin((tmpy - tmpx), (-tmpy - tmpx));
            if(j) ++tmpans, tmpx *= -1;
            if(tmpx == y) ans = min(ans, tmpans);
        }
    }
    cout << ans << endl;
}
