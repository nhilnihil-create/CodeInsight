#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const ll powll = 1LL<<1;

int main(void){
    int n; cin >> n;
    ll ans = 1;
    rep(i,0,n){
        ll t; cin >> t;
        ans =  ans/__gcd(ans, t)*t;
    }
    cout << ans << "\n";
} 