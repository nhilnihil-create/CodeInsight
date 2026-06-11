#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N;cin>>N;
    vector<int>A(3*N);
    REP(i,3*N)cin>>A[i];
    sort(A.rbegin(),A.rend());
    int ans=0;
    REP(i,N){
        ans+=A[2*i+1];
    }
    cout<<ans<<endl;
}
