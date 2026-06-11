#include <iostream>

int main(){
   int N, K;
   std::cin >> N >> K;
   int ans = K;
   for (int i=0; i<N-1; i++){
      ans = ans * (K-1);
   }
   std::cout << ans << std::endl;
}

