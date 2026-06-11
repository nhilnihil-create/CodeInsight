#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> L;
  long long N;
  std::cin >> N;
  L.resize(2*N);
  for (int i = 0; i < 2*N; i++) 
    std::cin >> L[i];
  std::sort(L.begin(), L.end());
  int sum = 0;
  for (int i = 0; i < N; i++)
    sum += std::min(L[2*i], L[2*i+1]);
  std::cout << sum << std::endl;
  return 0;
}