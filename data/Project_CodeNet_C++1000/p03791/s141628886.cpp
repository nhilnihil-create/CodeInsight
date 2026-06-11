#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int64_t const M = 1e9+7;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int> x(N);
  for(int i = 0; i < N; ++i) std::cin >> x[i];
  std::map<int,int> m;
  int count = 0;
  for(int i = 0; i < N; ++i) {
    ++m[i-count];
    if(x[i] >= count*2+1) ++count;
  }
  count = 0;
  int64_t ans = 1;
  for(int t = 0; t < N; ++t) {
    if(m.count(t)) count += m[t];
    (ans *= count) %= M;
    --count;
  }
  fin(ans);
  return 0;
}
