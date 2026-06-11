#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, x; std::cin >> N >> x;
  std::vector<int> a(N);
  int64_t ans = 0;
  for(int i = 0; i < N; ++i) {
    std::cin >> a[i];
    ans += a[i];
  }
  for(int64_t k = 1; k < N; ++k) {
    int64_t cur = k*x;
    if(cur >= ans) continue;
    int save = a[N-1];
    for(int i = N-1; i > 0; --i) a[i] = std::min(a[i], a[i-1]);
    a[0] = std::min(a[0], save);
    for(int i: a) cur += i;
    ans = std::min(ans, cur);
  }
  fin(ans);
  return 0;
}
