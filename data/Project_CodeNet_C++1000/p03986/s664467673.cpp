#include <string>
#include <iostream>

int main() {
  // そこまでのsの数より多いtはすべて残る
  // 逆に、それ以降のtの数より多いsは全て残る
  std::string x;
  std::cin >> x;
  int s = 0, ans = 0;
  for (int i = 0;i < x.size();i++) {
    if (x[i] == 'T') {
      if (s == 0) {
        ans++;
      } else {
        s--;
      }
    } else {
      s++;
    }
  }
  std::cout << ans + s << '\n';
  return 0;
}