#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
int main(){
    ll k,t;cin>>k>>t;
    vector<ll> a(t);rep(i,t)cin>>a[i];
    ll ans=0;
    sort(a.begin(),a.end());
    ll b =k-a[t-1];
    ans=max(a[t-1]-1.0-b,0.0);
    cout<<ans<<endl;
}