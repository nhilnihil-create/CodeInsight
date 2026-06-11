#include <bits/stdc++.h>

int main(void)
{
  std::string s;
  std::cin >> s;

  std::list<int> ans;

  int cnt = 0;
  while (cnt < s.size()) {
    if (s[cnt] == '0') {
      ans.push_back(0);
    }
    else if (s[cnt] == '1') {
      ans.push_back(1);
    }
    else {
      if (!ans.empty()) {
        ans.pop_back();
      }
    }
    cnt++;
  }

  while (!ans.empty()) {
    std::cout << ans.front();
    ans.pop_front();
  }
  std::cout << std::endl;

  return 0;
}