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
  ll i=0,ans=0;string S;cin>>S;
  while(S[i]=='T')i++;
  while(i<S.size()){
    ll j=i;while(j<S.size()&&S[j]=='S')j++;
    ans+=j-i;ll k=j;
    while(k<S.size()&&S[k]=='T')k++;
    ans=max((ll)0,ans-k+j);
    i=k;
  }
  cout<<2*ans<<endl;
  return 0;
}