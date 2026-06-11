#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
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
int mp[2000][2000];


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,x;
  cin>>n>>x;
  rep(i,n) cin>>mp[0][i];
  int ans=INF,sum=0;
  repi(i,1,n){
    sum=0;
    rep(j,n){
      mp[i][j]=min(mp[i-1][j],mp[0][(j-i+n)%n]);
      sum+=mp[i][j];
    }
    ans=min(ans,sum+(x*i));
    //cout<<sum<<endl;
  }

  // cout<<ans<<endl;
  sum=0;
  rep(i,n){
    sum+=mp[0][i];
    // cout<<sum<<endl;
  }
   ans=min(ans,sum);
  cout<<ans<<endl;
    

  return 0;
}
