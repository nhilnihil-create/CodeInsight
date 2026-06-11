#include <iostream>

int main()
{
  int a, b, c;
  std::string res = "NO";
  std::cin >> a >> b >> c;
  if((a == 7 && b == 5 && c == 5) ||
    (a == 5 && b == 7 && c == 5 ) ||
    (a == 5 && b == 5 && c == 7))
  {
    res = "YES";
  }
  std::cout << res;
  return 0;
}