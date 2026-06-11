#include <bits/stdc++.h>

int main(void)
{
  int num;
  int cnt_five = 0;
  int cnt_seven = 0;

  for (int i = 0; i < 3; i++) {
    std::cin >> num;

    if (num == 5) {
      cnt_five++;
    }
    else if (num == 7) {
      cnt_seven++;
    }
  }

  if ((cnt_seven == 1) && (cnt_five == 2)) {
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }
  
  return 0;
}