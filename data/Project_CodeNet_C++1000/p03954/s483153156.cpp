#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

inline int rd() {
  int s = 0, w = 1; char c = getchar();
  while (c < '0' || c > '9') { if (c == '-') w = -1; c = getchar(); }
  while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + c - '0', c = getchar();
  return s * w;
}

int n, a[N], mn = 0x3f3f3f3f, mx;
bool b[N];

inline bool chk(int x) {
  int tot[2]; tot[0] = tot[1] = 0;
  for (int i = 1; i <= 2 * n - 1; i++)
    if (a[i] >= x) b[i] = 1, tot[1]++;
    else b[i] = 0, tot[0]++;
  int pl = n - 1, pr = n + 1;
  while (pl >= 1 && pr <= 2 * n - 1) {
    if (b[pl] == b[pl + 1]) {
      if (b[pl] == 0) return false;
      return true;
    }
    if (b[pr] == b[pr - 1]) {
      if (b[pr] == 0) return false;
      return true;
    }
    pl--, pr++;
  }
  if (tot[0] > tot[1]) return false;
  return true;
}

int main() {
  n = rd();
  for (int i = 1; i <= 2 * n - 1; i++) {
    a[i] = rd();
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  int l = mn, r = mx, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}