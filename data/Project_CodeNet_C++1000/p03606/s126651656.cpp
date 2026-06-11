#include <iostream>

int main(void){
  int n, l, r, count = 0, i;
  std::cin >> n;
  for(i = 0; i < n; i++){
    std::cin >> l >> r;
    count += r - l + 1;
  }
  std::cout << count << std::endl;
  return 0;
}