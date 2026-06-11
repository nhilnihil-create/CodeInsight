#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
inline void add(int &x, int v) { x += v; if (x >= MOD) x -= MOD; }

const int inv2 = 500000004;
int N, L;
string S;
int dp[5001][5001];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> S;
  L = S.length();
  dp[0][0] = true;
  rep(i, N) {
    rep(j, N) {
      add(dp[i+1][j+1], (2LL*dp[i][j])%MOD);
      add(dp[i+1][max(j-1, 0)], dp[i][j]);
    }
  }
  int m = dp[N][L];
  rep(i, L) m = (1LL*m*inv2) % MOD;
  cout << m << "\n";
  return 0;
}
