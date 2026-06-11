#include <iostream>
#include <string>

int main(){
   int N, A, B;
   std::cin >> N >> A >> B;
   std::string S;
   std::cin >> S;
   int nai = 0;
   int gai = 0;
   for (int i=0; i<N; i++){
      if (S.at(i) == 'a'){
         if (nai+gai < A+B){
            nai++;
            std::cout << "Yes" << std::endl;
         } else{
            std::cout << "No" << std::endl;
         }
      } else if (S.at(i) == 'b'){
         if ((nai+gai < A+B) && (gai < B)){
            gai++;
            std::cout << "Yes" << std::endl;
         } else{
            std::cout << "No" << std::endl;
         }
      } else{
         std::cout << "No" << std::endl;
      }
   }
}

