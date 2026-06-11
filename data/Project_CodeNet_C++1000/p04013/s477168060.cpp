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
  rep(i,n) cin >> x[i];
  ll dp[n+10][n+10][50*n+100]={};
  dp[0][0][0]=1;
  
  rep(i,n){
    for(int j=0;j<=n;j++){
      for(int k=0;k<=50*n;k++){
        if(dp[i][j][k]==0)continue;
        dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
        dp[i+1][j][k]+=dp[i][j][k];
      }
    }
  }
  ll res = 0;
  for(int i=1;i<=n;i++){
    res+=dp[n][i][i*a];
  }
  cout << res << endl;
  return 0;
}
