#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;


ll f(ll x){
    if(x==1)return 1;
    return (x*f(x-1))%MOD;
}


int main(){
    ll n,m; cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0<<endl;
        return 0;
    }else if(n==m){
        cout<<(f(n)*f(m)*2)%MOD<<endl;
    }else{
        cout<<(f(n)*f(m))%MOD<<endl;       
    }
}