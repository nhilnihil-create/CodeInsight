#include <iostream>

int main(){
  int a,b,c;
  std::cin >> a >> b >> c;
  
  if(a==7 && b==5 && c==5){
    std::cout << "YES" << std::endl;
    return 0;
  }
  if(a==5 && b==7 && c==5){
    std::cout << "YES" << std::endl;
    return 0;
  }
  if(a==5 && b==5 && c==7){
    std::cout << "YES" << std::endl;
    return 0;
  }
  
  std::cout << "NO" << std::endl;
  
  return 0;
}
