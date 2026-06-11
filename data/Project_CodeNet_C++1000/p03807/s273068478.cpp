#include <iostream>

int main() {
  int N;
  std::cin >> N;
  long n, sum = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> n;
    sum += n;
  }
  std::cout << (sum % 2 == 0 ? "YES" : "NO") << std::endl;
}
