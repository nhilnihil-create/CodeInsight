#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
const ll mod = 1e9+7;
int main(){
    int n, m; cin >> n >> m;
    ll xsum = 0, ysum = 0;
    vector<ll> x(n),y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    rep(i,n){
        xsum += ((2*i-n+1)*x[i]) % mod;
        xsum %= mod;
    }
    rep(i,m){
        ysum += ((2*i-m+1)*y[i]) % mod;
        ysum %= mod;
    }
    cout << (xsum*ysum) % mod << endl;
}