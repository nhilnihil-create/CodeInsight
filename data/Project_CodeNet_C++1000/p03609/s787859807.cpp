#include <iostream>
 
int main(){
	int x,t; std::cin >> x >> t;
  if(x-t<0) x=t;
  std::cout << x-t << "\n";
}