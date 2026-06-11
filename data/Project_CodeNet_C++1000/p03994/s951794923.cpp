#include <iostream>

#define int long long

signed main() {
  std::string s;
  std::cin >> s;

  int n = s.length();
  
  int k;
  std::cin >> k;

  for(int i = 0; i < n-1; i++) {
    int need = 'z' - s[i] + 1;
    if(need <= k && need != 26) {
      s[i] = 'a';
      k -= need;
    }
  }

  s[n-1] = (char) ('a' + ((int) (s[n-1] - 'a') + k)%26);
  std::cout << s << std::endl;
}

