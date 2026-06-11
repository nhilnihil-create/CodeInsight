#include <iostream>

int main(void){
  int n, k, x, disp = 0, i;
  std::cin >> n >> k;
  for(i = 0; i < n; i++){
    std::cin >> x;
    disp += (x < k-x) ? x*2 : (k-x)*2;
  }
  std::cout << disp << std::endl;
  return 0;
}