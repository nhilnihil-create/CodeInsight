#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N,T;
    cin>>N>>T;
    int ans=T;
    int t[N];
    REP(i,N)cin>>t[i];
    REP(i,N-1) ans+=min(T,t[i+1]-t[i]);
    cout<<ans<<endl;
}