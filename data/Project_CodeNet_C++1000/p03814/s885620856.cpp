#include <bits/stdc++.h>

int main(void)
{
  std::string S;
  std::cin >> S;

  int first = (int)S.find('A');
  int last  = (int)S.rfind('Z');

  std::cout << last - first + 1 << std::endl;

  return 0;
}