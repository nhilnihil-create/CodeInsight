#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;
const int MOD = 1e9 + 7;

const int N = 6000;
char s[N];
int dp[N][N];

void add(int& x, int y) {
  x = ((int64)x + y) % MOD;
  if (x < 0) x += MOD;
}

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%s", s);
  m = strlen(s);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      add(dp[i + 1][max(0, j - 1)], dp[i][j] * (1 + (j > 0 && j <= m)));
      add(dp[i + 1][j + 1], dp[i][j] * (1 + (j >= m)));
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
