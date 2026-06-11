#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), elm(n, 0);
  for (int &e : a) {
    std::cin >> e;
    elm[e]++;
  }
  
  const int min = *std::min_element(a.begin(), a.end());
  const int max = min * 2 - (elm[min] == 2);
  
  bool ans = (elm[min] < 3);
  for (int i = min + 1; i <= max; i++) {
    ans &= (elm[i] > 1);
  }
  for (int i = max + 1; i < n; i++) {
    ans &= (elm[i] == 0);
  }
  
  std::cout << (ans ? "Possible" : "Impossible") << '\n';
  
  return 0;
}