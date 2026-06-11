#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n;
    cin>>n;

    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        if(ans>=1000000007) ans%=1000000007;
    }
    cout<<ans<<"\n";
    return 0;
}