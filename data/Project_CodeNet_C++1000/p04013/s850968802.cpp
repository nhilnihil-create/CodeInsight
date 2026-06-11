#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int MAX = 55;

ll dp[MAX][MAX*MAX*2];
int n, a;

int main(){
  cin >> n >> a;

  REP(i, 1, n){
    int x;
    cin >> x;
    x -= a;
    REP(j, 0, MAX*MAX*2){
      if(j-x >= 0) dp[i][j] += dp[i-1][j-x];
      dp[i][j] += dp[i-1][j];
    }
    dp[i][MAX*MAX+x]++;
  }

  cout << dp[n][MAX*MAX] << endl;

  return 0;
}
