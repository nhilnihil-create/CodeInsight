#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int Q,H,S,D,N;cin>>Q>>H>>S>>D>>N;
    if(H>Q*2)H=Q*2;
    if(S>H*2)S=H*2;
    if(D>S*2)D=S*2;
    cout<<N/2*D+(N%2)*S<<endl;
}