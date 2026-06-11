#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll q,h,s,d; cin>>q>>h>>s>>d;
    ll n; cin>>n;
    ll res=q*4*n;
    chmin(res, h*2*n);
    chmin(res, s*n);
    if(n%2==0) chmin(res, d*n/2);
    else{
        chmin(res, d*(n/2)+4*q);
        chmin(res, d*(n/2)+2*h);
        chmin(res, d*(n/2)+s);
    }
    cout<<res<<endl;
    return 0;
}