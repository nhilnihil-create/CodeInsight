#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>

template<typename T>
void fin(T const& v){ std::cout << v << std::endl; exit(0); }
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int64_t N; std::cin >> N;
  std::vector<int64_t> A(N);
  for(auto& v: A) std::cin >> v;
  int64_t sum = 0, n2 = N*(N+1)/2;
  for(auto v: A) sum += v;
  if(sum%n2 != 0) fin("NO");
  int64_t d = sum/n2;
  for(int i = 0; i < N; ++i) A[i] -= d*(i+1);
  std::vector<int64_t> ix(N, 0);
  ix[0] = d;
  for(int i = 0; i < N-1; ++i) {
    int64_t diff = A.back() - A[i];
    if(diff%N != 0) fin("NO");
    diff /= N;
    ix[i] += diff;
    if(ix[i] < 0) fin("NO");
    ix[i+1] -= diff;
  }
  if(ix.back() < 0) fin("NO");
  fin("YES");
  return 0;
}