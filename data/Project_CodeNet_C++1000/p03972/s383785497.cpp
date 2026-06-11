#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w,h;cin>>w>>h;
    vector< pair<ll,ll> > a;
    for(ll i=0;i<w;i++){
        ll x;cin>>x;
        a.push_back({x,0});
    }
    for(ll i=0;i<h;i++){
        ll x;cin>>x;
        a.push_back({x,1});
    }
    sort(a.begin(),a.end());
    ll ans=0;
    w+=1;
    h+=1;
    for(auto &ele:a){
        if(ele.second==1)ans+=w*ele.first,h--;
        else ans+=h*ele.first,w--;
    }
    cout<<ans;
}