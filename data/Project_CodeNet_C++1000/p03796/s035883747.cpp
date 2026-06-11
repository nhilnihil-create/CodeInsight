#include <iostream>
int main() {
  long long N, a{1};
  std::cin >> N;
  while (N) a = a * N-- % 1000000007;
  std::cout << a << "\n";
  return 0;
}
