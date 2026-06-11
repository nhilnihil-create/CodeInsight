#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int cnt[26]={0};
  string s;
  cin>>s;
  int ans=(s.size()*(s.size()-1))/2;
  rep(i,s.size() ){
    cnt[s[i]-'a']++;
  }
  rep(i,26 ){
    ans-=(cnt[i]*(cnt[i]-1))/2;
  }
  cout<<ans+1<<endl;
    
  
  

  return 0;
}
