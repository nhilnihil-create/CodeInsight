#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll mod=1e9+7;
    int n,m;
    cin>>n>>m;
    ll ans=0;
    ll ak=1,bk=1;
    for(int i=1;i<=n;++i){
        ak*=i;
        ak%=mod;
    }
    for(int i=1;i<=m;++i){
        bk*=i;
        bk%=mod;
    }
    if(abs(n-m)>1){
        cout<<ans<<endl;
        return 0;
    }
    else if(abs(n-m)==1){
        ans=(ak%mod)*(bk%mod);
    }
    else ans=2*(ak%mod)*(bk%mod);
    cout<<ans%mod<<endl;
    return 0;
}