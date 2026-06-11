#include <iostream>
#include <string>
#include <algorithm>

int main(){
   std::string S;
   std::cin >> S;
   size_t N = S.size();
   std::sort(S.begin(), S.end());
   S.erase(std::unique(S.begin(), S.end()), S.end());
   size_t newN = S.size();
   if (N == newN)
      std::cout << "yes" << std::endl;
   else
      std::cout << "no" << std::endl;
}

