#include "bits/stdc++.h"
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pl pair<ll,ll>
#define rep(i,b) for(ll i=0;i<b;i++)

using namespace std;
ll n,t,ans=0;
int main(){
    cin>>n>>t;
    vl a(n);
    rep(i,n)cin>>a[i];
    rep(i,n-1)ans+=min(a[i+1]-a[i],t);
    cout<<ans+t<<endl;
}

