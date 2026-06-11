#include <iostream>

int main(){
  int a,b,c;
  std::cin >> a >> b >> c;
  
  if(a==b || b==c || c==a){
    if(a==b && b==c){
      std::cout << 1 << std::endl;
      return 0;
    }
    else{
      std::cout << 2 << std::endl;
      return 0;
    }
  }
  std::cout << 3 << std::endl;
  
  return 0;
}
