#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,a;
  cin >> n >> a;
  vector<int>x(n);
  rep(i,n){
    cin >> x[i];
    x[i]-=a;
  }
  ll dp[n+10][5000]={};
  dp[0][2500]=1;
  
  rep(i,n){
    for(int j=0;j+x[i]<5000;j++){
      if(dp[i][j]==0)continue;
      dp[i+1][j+x[i]]+=dp[i][j];
      dp[i+1][j]+=dp[i][j];
    }
  }
  ll res = dp[n][2500]-1;
  cout << res << endl;
  return 0;
}
