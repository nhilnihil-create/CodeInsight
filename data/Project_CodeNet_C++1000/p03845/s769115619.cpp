#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> t(n);
    ll sum=0;
    rep(i,n){
        cin>>t[i];
        sum+=t[i];
    }
    int m;
    cin>>m;
    vector<ll> p(m),x(m);
    rep(i,m) cin>>p[i]>>x[i];
    vector<ll> ans(m);
    rep(i,m){
        ans[i]=sum-t[p[i]-1]+x[i];
        cout<<ans[i]<<"\n";
    }
    return 0;
}