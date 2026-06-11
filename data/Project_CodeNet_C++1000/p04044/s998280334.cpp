#include <bits/stdc++.h>

int main(void)
{
  int n, l;
  std::cin >> n >> l;

  std::vector<std::string> str;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    str.push_back(s);
  }

  std::sort(str.begin(), str.end());

  for (auto i : str) {
    std::cout << i;
  }
  std::cout << std::endl;

  return 0;
}