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
    int H,W,N;cin>>H>>W>>N;
    int A[N];
    int S[H][W];
  	REP(i,H)REP(j,W)S[i][j]='0';
    REP(i,N)cin>>A[i];
    int count=0;
    REP(i,N){
        REP(j,A[i]){
            if((count/W)%2==0)S[count/W][count%W]=1+i;
            else S[count/W][W-1-count%W]=1+i;
          	count++;
        }
    }
    REP(i,H){
        REP(j,W)cout<<S[i][j]<<" ";
        cout<<endl;
    }
}
