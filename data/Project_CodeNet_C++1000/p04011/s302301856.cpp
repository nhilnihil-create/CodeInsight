#include <iostream>
#include <vector>
#include<algorithm>

int main()
{
  int N, K, X, Y;
  std::cin >> N >> K >> X >> Y;

  std::cout << std::min(N,K)*X + std::max(N-K, 0)*Y << std::endl;
  return 0;
}