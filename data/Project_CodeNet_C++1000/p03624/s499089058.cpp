#include <iostream>
#include <string>
#include <algorithm>

int main(){
   std::string S;
   std::cin >> S;
   std::sort(S.begin(), S.end());
   S.erase(std::unique(S.begin(), S.end()), S.end());
   bool flag = true;
   char C;
   if (S.size() == 26){
      flag = false;
   } else{
      for (C = 'a'; C <= 'z'; C++){
         if (std::find(S.begin(), S.end(), C) == S.end()){
            break;
         }
      }
   }
   if (!flag)
      std::cout << "None" <<std::endl;
   else
      std::cout << C << std::endl;
}

