#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;


int main(){
  int n,a;
  cin >> n >> a;
  vector<int> x(n);
  int M = 0;
  rep(i,n){
    cin >> x.at(i);
    M = max(M,x.at(i));
  }
  vector<vector<vector<ll>>> dp(55, vector<vector<ll>>(55, vector<ll>(2600, 0)));

  for(int j = 0; j <= n; j++){
    for(int k = 0; k <= j; k++){
      for(int s = 0; s <= j*M; s++){
        if(j==0&&k==0&&s==0)dp.at(j).at(k).at(s)=1;
        else if(j>=1&&x.at(j-1)>s)dp.at(j).at(k).at(s)=dp.at(j-1).at(k).at(s);
        else if(j>=1&&k>=1&&s>=x.at(j-1))dp.at(j).at(k).at(s)=dp.at(j-1).at(k).at(s)+dp.at(j-1).at(k-1).at(s-x.at(j-1));
        else dp.at(j).at(k).at(s)=0;
        //cout<<dp.at(j).at(k).at(s)<<endl;
      }
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++)ans += dp.at(n).at(i).at(i*a);
  cout<<ans<<endl;
  return 0;
}
