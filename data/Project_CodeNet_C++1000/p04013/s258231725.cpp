#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  int n,a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i,n) cin >> x.at(i);
  rep(i,n) x.at(i) -= a;
  vector<vector<ll>> dp(n+1,vector<ll>(10000,0));
  dp.at(0).at(5000) = 1;
  for(int i=1;i<=n;i++){
    rep(j,10000){
      if(0 <= j-x.at(i-1) && j-x.at(i-1) < 10000 ){
        dp.at(i).at(j) = dp.at(i-1).at(j) + dp.at(i-1).at(j-x.at(i-1));
      }else{
        dp.at(i).at(j) = dp.at(i-1).at(j) ;
      }
    }
  }
  cout << dp.at(n).at(5000)-1 << endl;
  /*rep(i,n+1){
    for(int j=4990;j<5010;j++){
      cout << dp.at(i).at(j) << " ";
    }
    cout << endl;
  }*/

  return 0;
}

