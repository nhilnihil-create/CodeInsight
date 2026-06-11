#include <bits/stdc++.h>

int main(void)
{
  std::string str;
  std::cin >> str;

  int n = str.size() - 1;
  int64_t ans = 0;
  int64_t tmp;

  for (int i = 0; i < (1 << n); i++) {
    tmp = str[0] - '0';

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        ans += tmp;
        tmp = str[j+1] - '0';
      }
      else {
        tmp = tmp*10 + (str[j+1]-'0');
      }
    }
    ans += tmp;
  }
  std::cout << ans << std::endl;

  return 0;
}