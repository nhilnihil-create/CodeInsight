#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
ll gcd(ll x,ll y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
ll lcm(ll x,ll y){
    ll g=gcd(x,y);
    ll xb=x/g,yb=y/g;
    return xb*yb*g;
}
int main(void){
    ll n;cin>>n;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    sort(t.begin(),t.end());
    ll l=t[0];
    rep(i,n) l=lcm(l,t[i]);
    cout<<l<<endl;
}
