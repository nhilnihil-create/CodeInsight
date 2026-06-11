#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll keta (ll a) {
    if (a == 0) return 1;
    ll ret = 0;
    while(1) {
        if (a == 0) break;
        ++ret;
        a /= 10;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 1e18;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            //cout << i << " " << (n/i) << " " << keta(i) << " " << keta(n/i) << endl;
            ans = min(ans, max(keta(i), keta((n / i))));
        } 
    }
    cout << ans << endl;
    return 0;
}
