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
 
int modFac(int x){
    if(x==1)return 1;
    else return x%MOD*modFac(x-1)%MOD;
}

signed main(){
    int N,M;cin>>N>>M;
    if(M<N)swap(N,M);
    if(M-N>1)cout<<0<<endl;
    else{
        int ans=modFac(M)%MOD*modFac(N)%MOD;
      	if(M==N)ans=ans*2%MOD;
        cout<<ans<<endl;
    }
}