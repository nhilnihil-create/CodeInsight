#include <iostream>
#include <cmath>

int main(){
   long long int A, B, C;
   std::cin >> A >> B >> C;
   if ((A%2==0) || (B%2==0) || (C%2==0)){
      std::cout << 0 << std::endl;
   } else{
      long long int tmpA = std::abs((A*B*(C/2))-(A*B*(C-C/2)));
      long long int tmpB = std::abs((B*C*(A/2))-(B*C*(A-A/2)));
      long long int tmpC = std::abs((C*A*(B/2))-(C*A*(B-B/2)));
      std::cout << std::min(std::min(tmpA, tmpB), tmpC) << std::endl;
   }
}

