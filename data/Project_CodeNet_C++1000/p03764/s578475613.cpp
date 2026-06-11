#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const ll MOD = 1e9+7;

ll X[100100];
ll Y[100100];
int main(){
    ll n, m;
    cin >> n >> m;
    REP(i,n){
        ll x;
        cin >> x;
        X[i] = x;
    }
    REP(i,m){
        ll y;
        cin >> y;
        Y[i] = y;
    }

    ll sum = 0;
    ll xx = X[0];
    ll s = n-1;
    for(int i = 1; i < n; i++){
        ll x = X[i]; 
        ll diff = x - xx;
        ll num = i*(s+1-i);
        sum += diff*num;
        sum %= MOD;
        //cout << "s " << sum << endl;
        xx = x;
    }

    ll yy = Y[0];
    ll t = m-1;
    ll ans = 0;
    for(int j = 1; j < m; j++){
        ll y = Y[j];
        ll diff = y - yy;
        ll sumdiff = sum*diff;
        sumdiff %= MOD;
        ll num = j*(t+1-j);
        ans += num * sumdiff;
        ans %= MOD;
        //cout << "a " << ans << endl;
        yy = y;
    }

    cout << ans % MOD << endl;
    return 0;
}
