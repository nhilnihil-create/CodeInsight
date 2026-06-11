#include <bits/stdc++.h>

int main(void)
{
  std::string s;
  std::cin >> s;

  std::string ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      ans += "0";
    }
    else if (s[i] == '1') {
      ans += "1";
    }
    else {
      if (!ans.empty()) {
        ans.pop_back();
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}