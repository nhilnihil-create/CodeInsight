#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,K,i,a,A,m;cin>>N>>K;cin>>A;m=A;
  REP(i,N-1){cin>>a;A=__gcd(A,a);m=max(m,a);}
  if(K<=m&&K%A==0)cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  return 0;
}