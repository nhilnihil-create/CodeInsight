#include <iostream>
#include <map>

int main(){
   int N;
   std::cin >> N;
   std::map<long long int, int> A;
   for (int i=0; i<N; i++){
      long long int key;
      std::cin >> key;
      A[key]++;
   }
   int cnt = 0;
   for (auto x : A){
      if (x.second % 2 == 1){
         cnt++;
      }
   }
   std::cout << cnt << std::endl;
}

