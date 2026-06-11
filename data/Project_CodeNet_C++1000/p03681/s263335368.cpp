#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=1e9+7;
static ll f[(ll)1e5+10];
int main(void){
    ll n,m;
    cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0;
        return 0;
    }
    f[0]=1;
    rep(1,i,max(n,m)+1)f[i]=f[i-1]*i%mod;
    cout<<((abs(n-m)==1)?1:2)*f[n]%mod*f[m]%mod;
}
