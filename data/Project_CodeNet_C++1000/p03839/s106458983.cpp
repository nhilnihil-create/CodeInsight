#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, K; std::cin >> N >> K;
  std::vector<int64_t> psum(N+1), nsum(N+1);
  psum[0] = nsum[0] = 0;
  for(int i = 0; i < N; ++i) {
    int64_t a; std::cin >> a;
    if(a > 0) {
      psum[i+1] = psum[i] + a;
      nsum[i+1] = nsum[i];
    } else {
      psum[i+1] = psum[i];
      nsum[i+1] = nsum[i] + a;
    }
  }
  int64_t ans = 0; // all white
  for(int p = 0; p+K <= N; ++p) {
    ans = std::max(ans, psum[N] + nsum[p+K] - nsum[p]);
    ans = std::max(ans, psum[p] + psum[N] - psum[p+K]);
  }
  fin(ans);
  return 0;
}