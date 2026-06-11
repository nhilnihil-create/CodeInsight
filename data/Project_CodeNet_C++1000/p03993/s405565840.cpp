#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e20;

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    int ans=0;
    REP(i,N){
        int d=A[i]-1;
        if(A[d]-1==i)ans++;
    }
    cout<<ans/2<<endl;
}