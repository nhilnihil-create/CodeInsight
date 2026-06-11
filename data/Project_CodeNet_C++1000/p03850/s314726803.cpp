#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

int n;
LL b;
LL a[100010];
int t[100010];

LL dp[100010][5];
bool v[100010][5];
LL f(int x, int y) {
  if (y == 5) y -= 2;
  if (x >= n) return 0;
  LL &ret = dp[x][y];
  if (v[x][y]) return ret;
  v[x][y] = true;
  if (t[x] == 1) {
    if (y == 0)
      return ret = f(x + 1, y + 1) - a[x];
    else if (~y & 1) {
      return ret = max(f(x + 1, y) + a[x], f(x + 1, y + 1) - a[x]);
    }
    else
      return ret = f(x + 1, y + 1) + a[x];
  } else {
    if (~y & 1)
      return ret = f(x + 1, y) + a[x];
    else
      return ret = max(f(x + 1, y - 1) + a[x], f(x + 1, y) - a[x]);
  }
  return ret;
}

int main() {
  scanf("%d%lld", &n, &b);
  n--;
  char s[4];
  REP(i, n) {
    scanf("%s%lld", s, &a[i]);
    t[i] = s[0] == '+' ? 0 : 1;
  }
  cout << b + f(0, 0) << endl;
  return 0;
}

