#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, K; std::cin >> N >> K;
  std::vector<int> A(N), B(N);
  for(int i = 0; i < N; ++i) std::cin >> A[i] >> B[i];
  auto calc = [&](int x)->int64_t {
    int64_t res = 0;
    for(int i = 0; i < N; ++i) if((A[i]&x)==A[i]) res += B[i];
    return res;
  };
  int64_t ans = calc(K);
  for(int i = 29; i >= 0; --i) {
    int mask = 1<<i;
    if(0 == (mask&K)) continue;
    int cur = (K&-mask)-1;
    ans = std::max(ans, calc(cur));
  }
  fin(ans);
  return 0;
}
