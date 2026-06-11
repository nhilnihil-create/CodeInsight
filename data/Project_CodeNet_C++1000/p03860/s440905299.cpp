#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll modmul(ll a,ll b,ll mod){
    return a%mod * (b%mod) %mod;
}

ll modpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    else if(b%2==0) return modpow(modmul(a,a,mod),b/2,mod);
    else return modmul(modpow(a,b-1,mod),a,mod);
}

ll moddiv(ll a,ll b,ll mod){
    return a%mod * modpow(b,mod-2,mod) %mod;
}

int main(void)
{
    string a,b,c; cin>>a>>b>>c;
    cout<<'A'<<b[0]<<'C'<<endl;
    return 0;
}
