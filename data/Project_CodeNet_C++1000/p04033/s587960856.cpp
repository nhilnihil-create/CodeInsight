#include <iostream>

int main(){
   int a, b;
   std::cin >> a >> b;
   if ((a < 0) && (b >= 0)){
      std::cout << "Zero" << std::endl;
   } else if (a > 0){
      std::cout << "Positive" << std::endl;
   } else{
      if ((b-a+1) % 2 == 0){
         std::cout << "Positive" << std::endl;
      } else{
         std::cout << "Negative" << std::endl;
      }
   }
}

