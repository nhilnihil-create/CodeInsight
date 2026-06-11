#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll bikkuri(ll x){
    ll ret=1;
    if(x==0){
        return 1;
    }
    else {
        for (int i = 1; i <= x; ++i) {
            ret*=i%mod;
            ret%=mod;
        }
        return ret;
    }
}

int main(){
    ll n,m;cin>>n>>m;
    ll ans;
    ans=bikkuri(n)*bikkuri(m)%mod;
    ans%=mod;
    if(abs(n-m)>1)ans=0;
    if(abs(n-m)==0)ans*=2;
    ans%=mod;
    cout <<ans <<endl;
    return 0;
}

