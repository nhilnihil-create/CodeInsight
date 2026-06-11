#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
  }
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (a[a[i] - 1] == i + 1) {
      res++;
    }
  }
  std::cout << res / 2 << std::endl;
}