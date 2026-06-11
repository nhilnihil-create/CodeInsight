#include <iostream>
#include <string>

int main(void){
  std::string s; std::cin >> s;
  for(int i = 0; i < s.size(); i+= 2){
    std::cout << s[i];
  }
  std::cout << std::endl;
  return 0;
}
