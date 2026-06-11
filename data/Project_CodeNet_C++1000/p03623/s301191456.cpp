#include <iostream>
#include <cmath>

int main (){
  int x, a, b;
  char ans = 'A';
  std::cin >> x >> a >> b;
  a = std::abs(x - a) - std::abs(x-b);
  if(a > 0) ans = 'B';
  std::cout << ans << std::endl;
}
