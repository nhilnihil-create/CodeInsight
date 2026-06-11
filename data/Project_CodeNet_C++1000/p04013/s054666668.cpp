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
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;
const int mod = 1000000007;

ll dp[55][55][3000];

int main(){
  int N,A;
  cin >> N >> A;
  vector<int> x(N);
  for(int i=0; i<N; i++){
    cin >> x[i];
  }
  memset(dp,0,sizeof(dp));
  dp[0][0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<3000; k++){
        dp[i+1][j][k] += dp[i][j][k];
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
      }
    }
  }
  ll ans=0;
  for(int i=1; i<=N; i++){
    ans += dp[N][i][i*A];
  }
  cout << ans << endl;
  return 0;
}
