#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0;cin>>n;
    for(ll i=0,cur=1;i<n;i++){
        ll x;cin>>x;
        if(cur==x)cur++;
        else ans+=(x-1)/cur;
        if(cur==1)cur++;
    }
    cout<<ans;
}

