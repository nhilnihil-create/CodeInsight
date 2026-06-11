#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    std::cin >> a.at(i);

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == a.at(a.at(i)) && a.at(i) == a.at(a.at(a.at(i))))
      ++count;
  }
  std::cout << count / 2 << std::endl;
}
