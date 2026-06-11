#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int a[3];
  std::cin >> a[0] >> a[1] >> a[2];
  
  std::sort(a, a+3);
  if(a[2] == a[0]+a[1]){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
  
  return 0;
}
