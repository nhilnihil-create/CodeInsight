#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);

ll dp[101][301][101]={};

signed main(){
  ll n,we;cin>>n>>we;
  vector<ll> w(n),v(n);//相対値
  cin>>w[0]>>v[0];
  for(int i=1;i < n;i++)
  {
    cin>>w[i]>>v[i];
    w[i]-=w[0];
  }

  rep(j,301)dp[0][j][1]=v[0];

  for(int i=1;i < n;i++)
  {
    for(int j=0;j < 1+n*3;j++)
    {
      for(int k=0;k < n+1;k++)
      {

        if(k>0 && j>=w[i]) dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-w[i]][k-1]+v[i]);
        else dp[i][j][k]=dp[i-1][j][k];

        //if(i==3)cout<<j<<":"<<k<<":"<<dp[i][j][k]<<endl;
        
      }
    }
  }
  ll ans=0;
  for(int k=1;k < n+1;k++)
  {
    if(we-k*w[0]>=0){
      if(we-k*w[0]>3*k)ans=max(ans,dp[n-1][3*k][k]);
      else ans=max(ans,dp[n-1][we-k*w[0]][k]);
    }
  }

  cout<<ans<<endl;
}