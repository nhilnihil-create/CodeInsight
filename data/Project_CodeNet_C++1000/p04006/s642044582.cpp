#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> b(n,1e+18);
    ll res=1e+18;
    rep(i,n){
        ll tmp=0;
        rep(j,n){
            chmin(b[j],a[(j-i+n)%n]);
            tmp+=b[j];
        }
        tmp+=i*x;
        chmin(res,tmp);
    }
    cout<<res<<endl;
}
