#include <iostream>

int main() {
	int a,b,c,res;
  
  	std::cin >> a >> b >> c;
  
  	if (a == b && b == c) {
    	res = 1;
    } else if ( a == b || b == c || c == a) {
      	res = 2;
    } else {
    	res = 3;
    }
      
     std::cout << res << std::endl;
}