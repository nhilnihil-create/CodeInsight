#include <iostream>
int main() {
  long long N, M;
  std::cin >> N >> M;
  std::cout << (2*N<M ? N+(M-2*N)/4 : M/2) << "\n";
}
