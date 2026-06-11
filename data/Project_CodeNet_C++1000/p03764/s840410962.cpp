#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;
const int MOD = 1000000007;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    Rep (i, n) cin >> x[i];
    Rep (i, m) cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll width = 0, height = 0;

    Rep (i, n-1) {
        ll tmp = x[i+1] - x[i];
        tmp = tmp * (i+1) % MOD * (n-i-1) % MOD;
        width += tmp;
        width %= MOD;
    }

    Rep (i, m-1) {
        ll tmp = y[i+1] - y[i];
        tmp = tmp * (i+1) % MOD * (m-i-1) % MOD;
        height += tmp;
        height %= MOD;
    }

    ll ans = width * height % MOD;
    cout << ans << endl;
}