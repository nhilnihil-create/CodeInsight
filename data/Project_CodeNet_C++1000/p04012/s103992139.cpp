#include <bits/stdc++.h>

int main(void)
{
  std::string s;
  std::cin >> s;

  std::vector<int> cnt(26);
  for (size_t i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
  }

  bool flag = true;
  for (int i : cnt) {
    if (i & 0x01) {
      flag = false;
      break;
    }
  }

  if (flag) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
  
  return 0;
}