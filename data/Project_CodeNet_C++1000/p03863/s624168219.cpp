#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  int a=0,b=0;
  if(s.size() %2 ) a=1;
  if(s[0]==s[s.size() -1]) b=1;
  if((a+b)%2) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
    

  return 0;
}
