#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<size_t> p(N);
  for (size_t i=0; i<N; ++i) {
    scanf("%zu", &p[i]);
    --p[i];
  }

  int res=0;
  for (size_t i=0; i+1<N; ++i) {
    if (i == p[i]) {
      std::swap(p[i], p[i+1]);
      ++res;
    }
  }

  if (p[N-1] == N-1)
    ++res;

  printf("%d\n", res);
}
