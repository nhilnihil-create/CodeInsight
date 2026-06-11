#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int mod = 1e9+7;

ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a-=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<ll > > dp(n+2,vector<ll >(n+2));
  //  vector<vector<int> > ndp(n+2,vector<int >(n+2));
  rep(i,n+2)rep(j,n+2) dp[i][j]=0;
  dp[0][0]=1;  
  rep(j,n+1){
    rep(l,n+1){      
      if(l>=1){
	dp[j+1][l-1]+=dp[j][l];
	dp[j+1][l-1]%=mod;
      }
      else{
	dp[j+1][0]+=dp[j][0];
	dp[j+1][0]%=mod;	  
      }
      dp[j+1][l+1]+=dp[j][l]*2;
      dp[j+1][l+1]%=mod;
    }
    //    cout << dp[j+1][s.size()] << endl;
  }
  cout << dv(dp[n][s.size()],pw(2,s.size())) << endl;
  
  
  /*  cout << endl << endl;
      cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s"<<endl;*/
  return 0;
    

}
