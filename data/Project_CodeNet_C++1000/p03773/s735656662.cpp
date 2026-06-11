#include<iostream>

int main(){
  int a, b, h;
  std::cin >> a >> b;
  h = a + b;
  if(h >= 24)
    h -= 24;
  std::cout << h << std::endl;
  return 0;
}