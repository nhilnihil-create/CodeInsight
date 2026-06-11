#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;i++)

signed main(){
    ll N; cin>>N;
    vector<ll> a(N); 
    rep(i,N) cin>>a[i];
    ll ans=-1;
    map<ll,ll>cnt;
    for(auto x:a){
        cnt[x]++;
        cnt[x+1]++;
        cnt[x-1]++;
    }
    rep(i,N){
        ans=max(cnt[i],ans);
    }
    if(N==1)cout<<1<<endl;
    else cout<<ans<<endl;

}