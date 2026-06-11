#include <iostream>
#include <vector>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> a(N);
   for (int i=0; i<N; i++){
      std::cin >> a.at(i);
   }
   int cnt = 0;
   for (int i=0; i<N; i++){
      int tmp = a.at(i);
      if (i+1 == a.at(tmp-1)){
         cnt++;
      }
   }
   std::cout << cnt/2 << std::endl;
}

