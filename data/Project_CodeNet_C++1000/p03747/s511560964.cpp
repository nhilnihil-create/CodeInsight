#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,l,t; cin>>n>>l>>t;
    vector<ll> loc(n);
    ll counter=0;
    rep(i,n){
        ll x,w; cin>>x>>w;
        if(w==1)loc[i]=(x+t)%l;
        else loc[i]=((x-t)%l+l)%l;
        if(w==1){
            counter-=(t+x)/l;
        }else{
            counter+=(t+l-x-1)/l;
        }
    }
  	counter=(counter%n+n)%n;
    sort(loc.begin(),loc.end());
    vector<ll> ans(n);
    rep(i,n) ans[(i+counter)%n]=loc[i];
    rep(i,n) cout<<ans[i]<<endl;
    return 0;
}