#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    ll mod = 1e9 + 7;
    if(abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }
    ll ans;
    if(abs(n-m) == 1) ans = 1;
    else ans = 2;
    rep(i,n){
        ans *= (i+1);
        ans %= mod;
    }
    rep(i,m){
        ans *= (i+1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}