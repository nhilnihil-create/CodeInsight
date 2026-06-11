#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,a,b; cin>>n>>a>>b;
    vector<ll> x(n);
    rep(i,n) cin>>x[i];
    ll res=0;
    rep(i,n-1){
        if((x[i+1]-x[i])*a<b) res+=(x[i+1]-x[i])*a;
        else res+=b;
    }
    cout<<res<<endl;
    return 0;
}