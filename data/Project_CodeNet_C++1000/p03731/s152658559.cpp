#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll n,t; cin >> n >> t;
    vector<ll> s(n),u(n);
    rep(i,n){
       cin >> s[i]; 
    }
    u[0]=0;
    rep2(i,n){
        u[i]=s[i]-s[i-1];
        if(u[i]>t) u[i]=t;
    }
    ll ans=t;
    rep(i,n) ans+=u[i];
    cout << ans << endl;

}