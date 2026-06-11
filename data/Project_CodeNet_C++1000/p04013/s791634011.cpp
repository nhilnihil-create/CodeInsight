// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
#define MAX_N 55
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
ll dp[MAX_N][MAX_N][MAX_N*MAX_N]={};
signed main(){
  init_io();
  ll n,a,ans=0;
  cin >> n >> a;
  vector<ll> x(n);
  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  for(int i=0;i<n;i++){
    dp[i+1][1][x[i]]++;
    for(int j=1;j<MAX_N;j++){
      for(int k=0;k<MAX_N*MAX_N;k++){
        dp[i+1][j][k] += dp[i][j][k];
        if(k>=x[i]){
          dp[i+1][j][k] += dp[i][j-1][k-x[i]];
        }
      }
    }
  }
  for(int j=1;j<MAX_N;j++){
    for(int k=1;k<MAX_N*MAX_N;k++){
      if(j*a==k){
        ans+=dp[n][j][k];
      }
    }
  }
  cout << ans << endl;
}
