#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<ll> x(n),y(m);
    for(auto& xin:x) cin >> xin;
    for(auto& yin:y) cin >> yin;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll x_sum = 0,y_sum = 0;
    for(int i = 0; i < n;i++){
        (x_sum += ((i*x[i])%MOD - (n-(i+1))*x[i])%MOD + MOD)%=MOD;
    }
    for(int i = 0; i < m;i++){
        (y_sum += ((i*y[i])%MOD - (m-(i+1))*y[i])%MOD + MOD)%=MOD;
    }
    ll res = x_sum * y_sum;
    res%=MOD;
    cout << res << endl;
    return 0;
}
