#include <bits/stdc++.h>

int main(void)
{
  int h, w;
  std::cin >> h >> w;

  std::vector<std::string> c;
  for (int i = 0; i < h; i++) {
    std::string buf;
    std::cin >> buf;
    c.push_back(buf);
  }

  std::vector<std::string> px(2*h);
  for (int i = 0; i < 2*h; i++) {
    px[i] = c[i/2];
  }

  for (auto i : px) {
    std::cout << i << std::endl;
  }

  return 0;
}