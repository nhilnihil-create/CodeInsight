#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n,m;
    cin >> n >> m;
    int a = abs(n-m);
    bool ok = false;
    if(a < 2) ok = true;
    ll mod = 1e9 + 7;
    ll ans;
    if(ok){
        if(n == m) ans = 2;
        else ans = 1;
        rep(i,n){
            ans *= (i+1);
            ans %= mod;
        }
        rep(i,m){
            ans *= (i+1);
            ans %= mod;
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
}