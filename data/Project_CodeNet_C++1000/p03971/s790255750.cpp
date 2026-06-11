#include <iostream>
#include <vector>
int main(){
 int n, a, b;
 std::cin >> n;std::cin >> a;std::cin >> b;
 std::string s;
 std::cin >> s;
  
 int pnum = 0, bnum = 1; 
   
 for (size_t i=0; i < n; i++){
   bool pss = false;
   if (s[i] == 'a' && pnum < a+b){
     pss = true;
   }else if (s[i] == 'b' && pnum < a+b && bnum <= b){
     bnum += 1;
     pss = true;
   }
   if (pss){
     pnum += 1;
     std::cout << "Yes" << std::endl;
   }else{
   	 std::cout << "No" << std::endl;
   }
 }
}