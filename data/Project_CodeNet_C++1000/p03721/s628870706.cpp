#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll n;
    ll k;
    cin>>n>>k;
    vector<pair<ll,ll>>c(n);
    rep(i,n)cin>>c[i].first>>c[i].second;
    sort(c.begin(),c.end());

    for(int i=1;i<n;i++)c[i].second=c[i-1].second+c[i].second;
    
    ll ans=c[0].first;

    for(int i=0;i<n;i++){
        if(c[i].second>=k){
            ans=c[i].first;
            break;
        }
    }
    cout<<ans<<endl;

}