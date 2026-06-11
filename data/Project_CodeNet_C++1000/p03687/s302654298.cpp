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
  string s,t;cin>>s;int i,ans=100;char x;
  t=s;sort(ALL(t));
  REP(i,26){
    int S,j=0,c=0;x='a'+i;
    if(binary_search(ALL(t),x)){
      while(j<s.size()){
        S=j;
        while(j<s.size()&&s[j]!=x)j++;
        c=max(j-S,c);j++;
      }
      ans=min(c,ans);
    }
  }
  cout<<ans<<endl;
  return 0;
}