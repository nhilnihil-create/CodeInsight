#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>

constexpr int di[]={-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dj[]={-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  intmax_t H, W, N;
  scanf("%jd %jd %jd", &H, &W, &N);

  std::set<std::pair<int, int>> s;
  for (int i=0; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    s.emplace(a, b);
  }

  std::map<std::pair<int, int>, int> m;
  for (const auto &p: s) {
    int i=p.first, j=p.second;
    ++m[p];
    for (int k=0; k<8; ++k)
      ++m[std::pair<int, int>(i+di[k], j+dj[k])];
  }

  intmax_t res[10]={(H-2)*(W-2)};
  for (const auto &p: m) {
    int i=p.first.first, j=p.first.second;
    if (!(1 < i && i < H && 1 < j && j < W)) continue;
    if (p.second == 0) continue;
    fprintf(stderr, "(%d, %d) -> %d\n", i, j, p.second);
    ++res[p.second];
    --res[0];
  }

  for (int i=0; i<=9; ++i)
    printf("%zd\n", res[i]);
}
