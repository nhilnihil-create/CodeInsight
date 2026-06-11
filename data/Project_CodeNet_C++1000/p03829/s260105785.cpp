#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N,A,B;cin>>N>>A>>B;
    int X[N];
    REP(i,N)cin>>X[i];
    int ans=0;
    REP(i,N-1){
        ans+=min(B,A*(X[i+1]-X[i]));
    }
    cout<<ans<<endl;
}