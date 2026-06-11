#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    ll x, y;
    cin >> x >> y;
    ll ans = 1e18;
    rep(d1, 2) rep(d2, 2) {
        ll res = d1 + d2;
        ll xx = x * (d1 ? -1 : 1);
        ll yy = y * (d2 ? -1 : 1);
        if ( xx <= yy ) {
            ans = min(ans, res + yy - xx );
        }
    }
    cout << ans << endl;
    return 0;
}
