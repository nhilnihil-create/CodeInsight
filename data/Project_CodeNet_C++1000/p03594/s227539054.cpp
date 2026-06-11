#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f

template <class T> inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar())
    f ^= c == '-';
  for (; isdigit(c); c = getchar())
    x = x * 10 + (c ^ 48);
  x = f ? -x : x;
}

template <class T> inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T y = 1;
  int len = 1;
  for (; y <= x / 10; y *= 10)
    ++len;
  for (; len; --len, x %= y, y /= 10)
    putchar(x / y + 48);
}

int h, w, d;
char s[4] = {'R', 'Y', 'G', 'B'};

int main() {
  read(h), read(w), read(d);
  for (int i = 1; i <= h; ++i, putchar('\n'))
    for (int j = 1; j <= w; ++j) {
      int x = i + j + w, y = i - j + w;

      putchar(s[((x / d) & 1) * 2 + ((y / d) & 1)]);
    }
  return 0;
}
