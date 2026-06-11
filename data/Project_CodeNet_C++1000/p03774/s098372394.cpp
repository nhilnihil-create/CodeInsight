#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,m) cin>>c[i]>>d[i];
    vector<ll> cur(n,(ll)1e18);
    vector<int> ans(n);
    rep(i,n){
        rep(j,m){
            if(abs(a[i]-c[j])+abs(b[i]-d[j])<cur[i]){
                cur[i]=abs(a[i]-c[j])+abs(b[i]-d[j]);
                ans[i]=j+1;
            }
        }
    }
    rep(i,n) cout<<ans[i]<<endl;
}