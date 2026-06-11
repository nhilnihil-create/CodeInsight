#include <iostream>
#include <string>

int main(){
   int N;
   std::cin >> N;
   std::string S;
   std::cin >> S;
   int max = 0;
   int x = 0;
   for (int i=0; i<N; ++i){
      if (S.at(i) == 'I'){
         x++;
      } else{
         x--;
      }
      max = std::max(max, x);
   }
   std::cout << max << std::endl;
}

