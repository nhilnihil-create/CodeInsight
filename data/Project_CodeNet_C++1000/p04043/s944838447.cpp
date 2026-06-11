#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v(3);
  std::cin >> v[0] >> v[1] >> v[2];

  std::sort(v.begin(), v.end(), std::less<int>());
  bool is557 = (v[0] == 5) && (v[1] == 5) && (v[2] == 7);

  std::cout << (is557 ? "YES" : "NO") << std::endl;

  return 0;
}
