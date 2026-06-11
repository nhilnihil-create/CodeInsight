#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define inf (ll)1e9
#define d(x) cerr<<#x<<"="<<x<<endl;

int a[100001],mina[100001];

int main(void){
    int n,t;
    int ans=0;
    cin>>n>>t;
    rep(i,n)cin>>a[i];
    int minv=inf;
    rep(i,n){
        if(a[i]<minv)minv=a[i];
        mina[i]=minv;
    }
    int maxv=0;
    rep(i,n){
        if(maxv<a[i]-mina[i]){
            ans=1;
            maxv=a[i]-mina[i];
        }
        else if(maxv==a[i]-mina[i])ans++;
    }
    cout<<ans<<endl;
}
