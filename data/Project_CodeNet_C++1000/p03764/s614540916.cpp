#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const ll MOD = 1e9+7;

ll X[101010];
ll Y[101010];
int main(){
    int n,m;
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

    ll xsum = 0;
    REP(k,n){
        xsum += (k*X[k] - (n-k-1)*X[k]);
        xsum %= MOD;
    }

    ll ysum = 0;
    REP(k,m){
        ysum += (k*Y[k] - (m-k-1)*Y[k]);
        ysum %= MOD;
    }

    ll ans = (xsum*ysum) % MOD;

    cout << ans<< endl;
    return 0;
}
