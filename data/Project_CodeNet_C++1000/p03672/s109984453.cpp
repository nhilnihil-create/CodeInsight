#include <iostream>
#include <string>

int main(){
   std::string S;
   std::cin >> S;
   std::size_t N = S.size();
   std::string new_S = S; 
   int ans = 0;
   for (std::size_t i=2; i<N; i+=2){
      std::string new_S = S.substr(0, N-i);
      std::cerr << new_S << std::endl;
      if (new_S.substr(0, (N-i)/2) == new_S.substr((N-i)/2, (N-i)/2)){
         ans = N-i;
         break;
      }
   }
   std::cout << ans << std::endl;
}

