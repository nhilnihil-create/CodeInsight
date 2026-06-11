#include <iostream>
#include <string>

int main(){
   std::string S;
   std::cin >> S;
   int s, e;
   for (int i=0; i<S.size(); i++){
      if (S.at(i) == 'A'){
         s = i;
         break;
      }
   }
   for (int i=S.size()-1; i>=0; i--){
      if (S.at(i) == 'Z'){
         e = i;
         break;
      }
   }
   std::cout << e-s+1 << std::endl;
}

