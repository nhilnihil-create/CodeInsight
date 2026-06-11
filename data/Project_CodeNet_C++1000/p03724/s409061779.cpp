#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> nodes(n, 0);

  for (int i=0; i<m; i++) {
    int a, b;
    std::cin >> a >> b;
    nodes[a-1]++; nodes[b-1]++;
  }

  bool ans = std::all_of(nodes.begin(), nodes.end(),
                         [](int n) {return n%2==0;});

  std::cout << (ans ? "YES" : "NO") << std::endl;

  return 0;
}
