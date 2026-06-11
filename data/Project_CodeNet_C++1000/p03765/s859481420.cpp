#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

int main() {
  char buf[1<<17];
  scanf("%s", buf);
  std::string s = buf;
  scanf("%s", buf);
  std::string t = buf;

  size_t n = s.length();
  size_t m = t.length();
  std::vector<int> as(n+1), at(m+1);
  for (size_t i = 0; i < n; ++i)
    as[i+1] = as[i] + ((s[i] == 'A')? 1: 2);
  for (size_t i = 0; i < m; ++i)
    at[i+1] = at[i] + ((t[i] == 'A')? 1: 2);

  size_t q;
  scanf("%zu", &q);
  for (size_t i = 0; i < q; ++i) {
    size_t a, b, c, d;
    scanf("%zu %zu %zu %zu", &a, &b, &c, &d);
    int vs = (as[b]-as[a-1]) % 3;
    int vt = (at[d]-at[c-1]) % 3;
    puts((vs == vt)? "YES": "NO");
  }
}
