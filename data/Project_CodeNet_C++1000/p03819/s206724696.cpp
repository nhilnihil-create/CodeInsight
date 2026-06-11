// Written by newbiechd
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

const int BUFFER_SIZE = 1 << 25 | 1;
struct InputOutputStream {
  char ibuf[BUFFER_SIZE], obuf[BUFFER_SIZE], *s, *oh;
  InputOutputStream() : s(ibuf), oh(obuf) {
    ibuf[fread(ibuf, 1, BUFFER_SIZE, stdin)] = '\0';
  }
  ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }
  template <typename T>
  inline InputOutputStream &operator>>(T &x) {
    while (!isdigit(*s)) ++s;
    for (x = 0; isdigit(*s); ++s)
      x = x * 10 + (*s ^ '0');
    return *this;
  }
  template <typename T>
  inline InputOutputStream &operator<<(T x) {
    static char buf[23];
    register char *top = buf;
    if (x) {
      for (register int t; x; )
        t = x / 10, *top++ = x - t * 10 + 48, x = t;
      while (top != buf)
        *oh++ = *--top;
    }
    else
      *oh++ = '0';
    *oh++ = '\n';
    return *this;
  }
}IO;

template <typename lhs, typename rhs>
inline lhs min(const lhs &x, const rhs &y) { return x < y ? x : y; }
template <typename lhs, typename rhs>
inline lhs max(const lhs &x, const rhs &y) { return x > y ? x : y; }

const int maxN = 300007;
int m, n;

struct Fenwick {
  int s[maxN];
  inline void modify(int x, int v) {
    for (; x <= m; x += x & -x)
      s[x] += v;
  }
  inline int query(int x) {
    int o = 0;
    for (; x; x -= x & -x)
      o += s[x];
    return o;
  }
}bit;

std::pair<int, int> seg[maxN];
inline bool cmp(const std::pair<int, int> &x, const std::pair<int, int> &y) {
  return x.second - x.first < y.second - y.first;
}

int main() {
  IO >> n >> m, ++m;
  for (int i = 1; i <= n; ++i)
    IO >> seg[i].first >> seg[i].second, ++seg[i].first, ++seg[i].second;
  std::sort(seg + 1, seg + n + 1, cmp);
  
  int now = 1;
  for (int i = 1; i < m; ++i) {
    while (seg[now].second - seg[now].first + 1 < i && now <= n)
      bit.modify(seg[now].first, 1), bit.modify(seg[now].second + 1, -1), ++now;
    int ans = n - now + 1;
    for (int j = 1; j <= m; j += i)
      ans += bit.query(j);
    IO << ans;
  }
  return 0;
}
