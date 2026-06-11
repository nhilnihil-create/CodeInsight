#include<iostream>

int main(){
  int n1, n2, n3;
  std::cin >> n1;
  std::cin >> n2;
  std::cin >> n3;
  if(n1 == 7){
   if(n2 == 5 && n3 == 5){
	  std::cout << "YES" << std::endl;
     return 0;
   }
  }
  else if(n2 == 7){
    if(n1 == 5 && n3 == 5){
	  std::cout << "YES" << std::endl;
      return 0;
    }
  } else if(n3 == 7){
    if(n1 == 5 & n2 == 5){
	  std::cout << "YES" << std::endl;
      return 0;
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}