#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_N = 1000010;
ll N;
ll dp[MAX_N];
ll sum[MAX_N];
int main() {
  cin >> N;
  dp[1] = N;
  sum[1] = N;

  dp[2] = N * N % MOD;
  sum[2] = (sum[1] + dp[2]) % MOD;

  for (int i = 3; i <= N; i++){
    //1
    dp[i] = dp[i - 1];
    //A[i] >= 2 A[i - 1] >= 2
    dp[i] += (N - 1) * (N - 1) % MOD;
    //A[i] >= 2 A[i - 1] = 1
    dp[i] += (sum[i - 3] + (N - 1 - (i - 3))) % MOD;
    dp[i] %= MOD;
    sum[i] += (sum[i - 1] + dp[i]) % MOD;
  }

  cout << dp[N] << endl;
  return 0;
}
