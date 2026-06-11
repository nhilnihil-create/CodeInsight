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
int N,X;
int piyo(int x){
    if(x!=0)return x-1;
    if(x==0)return N-1;
}

signed main(){
    cin>>N>>X;
    int A[N];
    REP(i,N){
        cin>>A[i];
    }
    int ans=INF;
    int T[N][N];//T[1][2]はi=1のときのスライム2+1を取る最小時間(i=魔法回数)
    REP(i,N){
        if(i==0)REP(j,N)T[i][j]=A[j];
        else{
            REP(j,N)T[i][j]=min(T[i-1][piyo(j)],A[j]);
        }
    }
    REP(i,N){
        int preans=i*X;
        REP(j,N)preans+=T[i][j];
        ans=min(ans,preans);
    }
    cout<<ans<<endl;
}