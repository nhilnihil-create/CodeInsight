#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll res=max((ll)0,a[0]-x);
    a[0]-=res;
    rep(i,n){
        if(i==0)continue;
        ll buf=max((ll)0,(a[i]+a[i-1]-x));
        res+=buf;
        a[i]-=buf;
    }
    cout<<res<<endl;
}
