#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,A,B,i,ans=0;cin>>N>>A>>B;ll X[N];REP(i,N)cin>>X[i];
  REP(i,N-1)ans+=min(A*(X[i+1]-X[i]),B);
  cout<<ans<<endl;
  return 0;
}