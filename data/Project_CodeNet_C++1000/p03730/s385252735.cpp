#include <iostream>

int main(){
   int A, B, C;
   std::cin >> A >> B >> C;
   int i=1;
   while(1){
      if (A*i % B == C){
         std::cout << "YES" << std::endl;
         break;
      }
      if (A*i % B == 0){
         std::cout << "NO" << std::endl;
         break;
      }
      i++;
   }
}

