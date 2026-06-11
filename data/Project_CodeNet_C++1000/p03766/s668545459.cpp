#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int dp[1000000];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  dp[0] = 1;
  long long ans = 0;
  long long s = 1;
  rep(i, N-1) {
    dp[i+1] = (s - (i-1>=0?dp[i-1]:0) + MOD) % MOD;
    s = (s + dp[i+1]) % MOD;
    int g = (1LL*(N-1)*(N-1)+(N-max(2, N-i-1)+1)) % MOD;
    ans = (1LL*dp[i]*g + ans) % MOD;
  }
  ans = (ans + 1LL * dp[N-1] * N) % MOD;
  cout << ans << "\n";
  return 0;
}
