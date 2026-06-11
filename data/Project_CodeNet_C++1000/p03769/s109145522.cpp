#include <bits/stdc++.h>
#define RI register int
typedef long long LL;

#define FILEIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);

using namespace std;

int s[105], a[205];

int main() {
  
#ifdef LOCAL
  FILEIO("a");
#endif

  LL n; cin >> n;
  int tot = 0;
  while (n) s[++tot] = n & 1, n >>= 1;
  int L = 100, R = 99, tmp = 0;
  while (tot) {
    --tot;
    int cnt = 1;
    while (!s[tot] && tot > 0) --tot, ++cnt;
    if (!tot) --cnt;
    while (cnt > 0) a[++R] = ++tmp, --cnt;
    a[--L] = ++tmp;
  }
  printf("%d\n", 100 + (R - L + 1));
  for (RI i = L; i <= R; ++i) printf("%d ", a[i]);
  for (RI i = 1; i <= 100; ++i) printf("%d ", i);

  return 0;
}

// created by Daniel yuan
