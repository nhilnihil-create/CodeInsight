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

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    ll ans = t[0];
    for (int i = 1; i < n; ++i) {
        ans = lcm(ans, t[i]);
    }
    cout << ans << endl;
    return 0;
}
