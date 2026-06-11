#include <iostream>
#include <cmath>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int ret = 0;

  for(int i=0; i<N; i++) {
    int x;
    std::cin >> x;
    ret += std::min(x, std::abs(x-K));
  }

  std::cout << 2 * ret << std::endl;
  return 0;
}
