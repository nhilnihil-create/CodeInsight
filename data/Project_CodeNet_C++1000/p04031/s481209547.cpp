#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define pb push_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N;cin>>N;
    int A[N];
    REP(i,N)cin>>A[i];
    int cost=INF;
    for(int i=-100;i<=100;i++){
        int pre=0;
        REP(j,N){
            pre+=(i-A[j])*(i-A[j]);
        }
        cost=min(cost,pre);
    }
    cout<<cost<<endl;
}