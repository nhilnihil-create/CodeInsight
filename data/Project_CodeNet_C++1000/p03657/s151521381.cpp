#include<iostream>

int main(){
  int a, b;
  std::cin >> a >> b;
  if(a%3 == 0)
    std::cout << "Possible" << std::endl;
  else if(b%3 == 0)
    std::cout << "Possible" << std::endl;
  else if((a + b)%3 == 0)
    std::cout << "Possible" << std::endl;
  else
    std::cout << "Impossible" << std::endl;
}
