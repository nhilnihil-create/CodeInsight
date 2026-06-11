#include <iostream>
#include <algorithm>
int main(){
 int x,n=1,add=1;
 std::cin >> x;
 for(int i=2;i<x+1;i++)
  if(n<x){
   n+=i;
   add++;
  }
  else{
   std::cout << std::min(add,x) << std::endl;
   return 0;
  }
  std::cout << x << std::endl;
}