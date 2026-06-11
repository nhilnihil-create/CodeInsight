#include <iostream>
#include <vector>
#include <string>

bool match4(const std::string& S,
            std::string::const_iterator begin)
{
  if (begin == S.end()) return true;

  std::vector<std::string> match_list = {"dream", "dreamer", "erase", "eraser"};

  bool judge = false;
  for (auto m : match_list) {
    std::string target(begin, begin+m.size());
    // std::cout << target << " " << m << std::endl;
    if (target == m) judge = judge || match4(S, begin+m.size());
  }

  return judge;
}

int main()
{
  std::string S;
  std::cin >> S;

  std::cout << (match4(S, S.begin()) ? "YES" : "NO") << std::endl;
}