#include <iostream>
#include <string>

int main()
{
  std::string a, b, c;

  std::cin >> a >> b >> c;

  if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
