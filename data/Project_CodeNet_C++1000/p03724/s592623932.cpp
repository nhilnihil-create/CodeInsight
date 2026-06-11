#include <bits/stdc++.h>
using namespace std;
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
const int N = 100005;
int n, q, a[N];
int main() {
  read(n), read(q);
  q *= 2;
  while (q--) {
    int x;
    read(x);
    a[x] ^= 1;
  }
  puts(*max_element(a + 1, a + n + 1) ? "NO" : "YES");
  return 0;
}