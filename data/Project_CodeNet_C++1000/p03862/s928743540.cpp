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

signed main(){
    int N,X;cin>>N>>X;
    int A[N];
    REP(i,N)cin>>A[i];
    int ans=0;
    if(A[0]>X){
        ans+=A[0]-X;
        A[0]=X;
    }
    REP(i,N-1){
        if(A[i]+A[i+1]>X){
            int d=A[i]+A[i+1]-X;
            if(A[i+1]>=d){
                ans+=d;
                A[i+1]-=d;
            }
            else{
                ans+=d;
                A[i+1]=0;
            }
        }
    }
    cout<<ans<<endl;
}