#include <bits/stdc++.h>

int main(void)
{
  std::vector<int> candy(3);
  for (int i = 0; i < 3; i++) {
    std::cin >> candy.at(i);
  }

  std::sort(candy.begin(), candy.end());

  if (candy.at(2) == (candy.at(0) + candy.at(1))) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}