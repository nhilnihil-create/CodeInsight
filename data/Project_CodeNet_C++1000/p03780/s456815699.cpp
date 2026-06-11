//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
//oh,i is a enlish men!!!
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = int;
void init_io()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(18);
}
ll n,k,ans=0;
void solve_dp(const vector<ll> &a,vector<vector<bool>> &dp){
  dp[0][0] = true;
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      dp[i+1][j] = dp[i+1][j] | dp[i][j];
      int x = min(k,j+a[i]);
      if(x<k){
        dp[i+1][x] = dp[i+1][x] | dp[i][j];
      }
    }
  }
}
signed main(){
  init_io();
  cin >> n >> k;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  const ll INF = 2e9;
  vector<vector<bool>> dp1(n+1,vector<bool>(k+1,false));
  vector<vector<bool>> dp2(n+1,vector<bool>(k+1,false));
  vector<ll> d1,d2;
  solve_dp(a,dp1);
  reverse(a.begin(),a.end());
  solve_dp(a,dp2);
  for(int i=0;i<n;i++){
    bool no_need = true;
    for(int j=0;j<k;j++){
      if(dp1[n-1-i][j]){
        d1.push_back(j);
      }
      if(dp2[i][j]){
        d2.push_back(j);
      }
    }
    d2.push_back(INF);
    for(auto j:d1){
      ll mi = max(0,k-a[i]-j);
      auto itr = lower_bound(d2.begin(),d2.end(),mi);
      if(*itr+j<k){
        no_need = false;
      }
    }
    if(no_need){
      ans++;
    }
    d1.clear();
    d2.clear();
  }
  cout << ans << endl;
}//@奆奆的蒟蒻  做
