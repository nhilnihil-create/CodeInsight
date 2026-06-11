#include <iostream>

int main(){
  char s[10000];
  for(int i=0; i<8; i++){
    std::cin >> s[i];
  }
  
  std::cout << "A" << s[7] << "C" << std::endl;
  
  return 0;
}
