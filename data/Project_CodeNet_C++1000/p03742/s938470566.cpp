#include <iostream>

int main() {
  long long a,b;
  std::cin >> a >> b;
  if(abs(a-b)<=1){
    std::cout << "Brown" << std::endl;
  }
  else{
    std::cout << "Alice" << std::endl;
  }
  return 0;
}