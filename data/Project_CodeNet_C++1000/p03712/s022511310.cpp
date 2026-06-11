#include <iostream>
#include <string>

int main(void){
  int h,w;
  std::string a[100];
  
  std::cin >> h >> w;
  for(int i=0;i<h;i++){
    std::cin >> a[i];
  }
  for(int i=0;i<w+2;i++){
    std::cout << "#";
  }
  std::cout << std::endl;
  for(int i=0;i<h;i++){
    std::cout << "#";
    std::cout << a[i];
    std::cout << "#" <<std::endl;
  }
  for(int i=0;i<w+2;i++){
    std::cout << "#";
  }
  std::cout << std::endl;
}

  