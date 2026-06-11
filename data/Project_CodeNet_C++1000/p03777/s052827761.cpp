#include <iostream>

int main () {
	std::string a,b, res;
  
  	std::cin >> a >> b;
  
  	if(a =="H") {
    	if(b=="H") {
          res = "H";
        } else {
          res = "D";
        }
    } else {
    	if (b=="H") {
          res = "D";
        } else {
          res = "H";
        }
    }
 	std::cout << res << std::endl;
}