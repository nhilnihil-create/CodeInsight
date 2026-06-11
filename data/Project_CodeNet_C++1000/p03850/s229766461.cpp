#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline void read(int &x) {
  x = 0;
  bool flag = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      flag = 1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  if (flag) {
    x = -x;
  }
}
int main() {
  int n;  
  read(n);
  long long f[3] = {0, -INF, -INF};
  for (int i = 1; i <= n; ++i) {
    int x;
    read(x);
    f[0] += x;
    f[1] -= x;
    f[2] += x;
    f[0] = max(f[0], f[1]);
    f[1] = max(f[1], f[2]);
    if (x < 0) {
      f[2] = max(f[2], f[1]);
      f[1] = max(f[1], f[0]);
    }
  }
  printf("%lld\n", f[0]);
  return 0;
}