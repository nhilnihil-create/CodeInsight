#include <iostream>
int main(){
  std::string s;
  std::cin >> s;
  int len = s.length();
  std::cout << s[0] << len - 2 << s[len-1] << std::endl;
  return 0;
}