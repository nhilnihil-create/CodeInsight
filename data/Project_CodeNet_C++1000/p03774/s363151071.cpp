#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n,m;
vector<ll> a(110),b(110),c(110),d(110),ans(110);

int main(){
    cin>>n>>m;
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,m) cin>>c[i]>>d[i];
    rep(i,n){
        ll res=INF;
        rep(j,m){
            ll l=abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(res>l){
                res=l;
                ans[i]=j+1;
            }  
        }
    }
    rep(i,n) cout<<ans[i]<<"\n";

    return 0;
}