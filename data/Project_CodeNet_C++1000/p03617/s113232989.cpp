#include <iostream>
#include <algorithm>

int main(){
   long long int Q, H, S, D, N;
   std::cin >> Q >> H >> S >> D >> N;
   long long int M = std::min(std::min(4*Q, 2*H), S);
   if (2*M <= D){
      std::cout << N*M << std::endl;
   } else{
      std::cout << (N/2)*D+(N%2)*M << std::endl;
   }

}

