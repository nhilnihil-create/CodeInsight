#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N;
    int ans=0;
  	cin>>N;
    REP(i,N){
        int a,b;cin>>a>>b;
        ans+=b-a+1;
    }
    cout<<ans<<endl;
}
