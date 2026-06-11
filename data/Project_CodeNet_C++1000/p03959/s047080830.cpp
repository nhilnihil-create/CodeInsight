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
    int N;cin>>N;
    int T[N],A[N],tlH[N],thH[N],alH[N],ahH[N];
  	REP(i,N)tlH[i]=thH[i]=alH[i]=ahH[i]=0;
    REP(i,N)cin>>T[i];
    REP(i,N)cin>>A[i];
    REP(i,N){
        if(i==0)tlH[i]=thH[i]=T[i];
        else{
            if(T[i]==T[i-1]){
                tlH[i]=1;thH[i]=T[i];
            }
            else tlH[i]=thH[i]=T[i];
        }
    }
    REP(i,N){
        if(i==0)alH[N-1-i]=ahH[N-1-i]=A[N-1-i];
        else{
            if(A[N-1-i]==A[N-i]){
                alH[N-1-i]=1;ahH[N-1-i]=A[N-1-i];
            }
            else alH[N-1-i]=ahH[N-1-i]=A[N-1-i];
        }
    }
    int ans=1;
    REP(i,N){
        int d=min(ahH[i],thH[i])-max(alH[i],tlH[i])+1;
        if(d<=0){
            ans=0;
        }
        ans*=d;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
