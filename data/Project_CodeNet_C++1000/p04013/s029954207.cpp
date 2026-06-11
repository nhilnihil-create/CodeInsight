#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------
ll dp[55][55][3000];
int main(){
  int N,A;
  cin >> N >> A;
  vector<int> x(N);
  for(int i=0; i<N; i++){
    cin >> x[i];
  }
  for(int i=0; i<55; i++){
    for(int j=0; j<55; j++){
      for(int k=0; k<3000; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<=i; j++){
      for(int k=0; k<3000; k++){
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
        dp[i+1][j][k] += dp[i][j][k];
      }
    }
  }
  ll ans = 0;
  for(int j=1; j<=N; j++){
    ans += dp[N][j][j*A];
  }
  cout << ans << endl;
  return 0;
}
