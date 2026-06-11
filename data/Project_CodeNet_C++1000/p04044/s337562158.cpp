#include <bits/stdc++.h>

int main(void)
{
  int n, l;
  std::cin >> n >> l;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s.at(i);
  }

  std::sort(s.begin(), s.end());

  for (std::string i : s) {
    std::cout << i;
  }

  printf("\n");

  return 0;
}