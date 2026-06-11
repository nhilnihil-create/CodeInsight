#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a>>b;
  int x[n];
  rep(i,n) cin>>x[i];
  int ans=0;
  int mx=(b/a);
  rep(i,n-1){
    if(x[i+1]-x[i] > mx){
      ans+=b;
    }else{
      ans+=(x[i+1]-x[i])*a;
    }
  }
  cout<<ans<<endl;
  return 0;
}
