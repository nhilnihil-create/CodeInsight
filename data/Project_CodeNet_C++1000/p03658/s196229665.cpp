#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e20;

signed main(){
    int N,K;cin>>N>>K;
    vector<int>A(N);
    REP(i,N) cin>>A[i];
    sort(A.rbegin(),A.rend());
    int ans=0;
    REP(i,K){
        ans+=A[i];
    }
    cout<<ans<<endl;
}