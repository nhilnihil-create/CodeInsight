#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> s(N);
   for (int i=0; i<N; ++i){
      std::cin >> s.at(i);
   }
   std::sort(s.begin(), s.end());
   int sum = std::accumulate(s.begin(), s.end(), 0);
   if (sum % 10 != 0){
      std::cout << sum << std::endl;
   } else{
      for (int i=0; i<N; i++){
         int sum2 = sum - s.at(i);
         if (sum2 % 10 != 0){
            std::cout << sum2 << std::endl;
            break;
         } else if (i == N-1){
            std::cout << 0 << std::endl;
         }
      }
   }


}

