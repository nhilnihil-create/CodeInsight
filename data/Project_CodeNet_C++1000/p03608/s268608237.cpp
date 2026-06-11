#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#define mod 1000000007
typedef long long ll;
using namespace std;

ll dp[205][205];
int R[10];
const ll INF = 1000000000;
int main(){
  int n,m,r; cin >> n >> m >> r;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j] = INF;
    }
  }
  for(int i=0;i<n;i++) dp[i][i] = 0;

  for(int i=0;i<r;i++){
    cin >> R[i];
    R[i]--;
  }
  sort(R,R+r);

  for(int i=0;i<m;i++){
    ll a,b,c; cin >> a >> b >> c;
    a--; b--;
    dp[a][b] = c;
    dp[b][a] = c;
  }

  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  ll ans = 10000000000000000;
  do{
    ll tmp = 0;
    for(int i=0;i<r-1;i++){
      tmp += dp[R[i]][R[i+1]];
    }
    ans = min(ans,tmp);
  }while(next_permutation(R,R+r));

  cout << ans << endl;
  return 0;
}