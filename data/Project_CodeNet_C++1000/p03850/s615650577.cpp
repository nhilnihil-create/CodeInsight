#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

const int MAX_N = 200020;

int dp[3][MAX_N];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n;
  cin >> n;
  fill(dp[0], dp[3], -inf);
  cin >> dp[0][0];
  rep(i, n-1) {
    char op;
    int a;
    cin >> op >> a;
    if(op == '+') {
      // ...+a
      dp[0][i+1] = max(dp[0][i]+a, dp[1][i]+a);
      // ...-(...+a OR ...-(...-(...)+a
      dp[1][i+1] = max(dp[1][i]-a, dp[2][i]-a);
      // ...-(...-(...+a
      dp[2][i+1] = dp[2][i]+a;
      // ...-(...-(...-(... EQ ...-(...-(...))-(...
    } else {
      // ALWAYS ...-(a
      dp[0][i+1] = -inf;
      // ...-(a OR ...-(...)-(a OR ...-(...-(...))-(a
      dp[1][i+1] = max({dp[0][i]-a, dp[1][i]-a, dp[2][i]-a});
      // ...-(...-(a OR ...-(...-(...)-(a
      dp[2][i+1] = max(dp[1][i]+a, dp[2][i]+a);
    }
  }
  cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << endl;


  return 0;
}
