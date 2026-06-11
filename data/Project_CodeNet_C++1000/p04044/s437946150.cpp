#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<std::string> strs(N);

  for(int i = 0; i<N; i++) {
    std::cin >> strs[i];
  }

  std::sort(strs.begin(), strs.end(), std::less<std::string>());
  std::string out;
  for(auto s : strs) out += s;

  std::cout << out << std::endl;

  return 0;
}
