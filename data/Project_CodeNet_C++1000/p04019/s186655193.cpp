#include <iostream>
#include <string>
#include <algorithm>

int main(){
   std::string S;
   std::cin >> S;
   bool fe = (std::find(S.begin(), S.end(), 'E') == S.end())? false : true;
   bool fw = (std::find(S.begin(), S.end(), 'W') == S.end())? false : true;
   bool fs = (std::find(S.begin(), S.end(), 'S') == S.end())? false : true;
   bool fn = (std::find(S.begin(), S.end(), 'N') == S.end())? false : true;
   if ((fe == fw) && (fs == fn)){
      std::cout << "Yes" << std::endl;
   } else{
      std::cout << "No" << std::endl;
   }
}

