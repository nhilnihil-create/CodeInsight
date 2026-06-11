#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int N, x; std::cin >> N >> x;
  if(x == 1 || x == N*2-1) fin("No");
  std::cout << "Yes\n";
  int n = 2;
  for(int i = 0; i < N-2; ++i) {
    if(n == x) ++n;
    std::cout << n << "\n";
    ++n;
  }
  std::cout << "1\n" << x << "\n" << (N*2-1) << "\n";
  for(int i = 0; i < N-2; ++i) {
    if(n == x) ++n;
    std::cout << n << "\n";
    ++n;
  }
  return 0;
}
