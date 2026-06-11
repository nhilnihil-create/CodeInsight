#include <iostream>

int main () {
	std::string a, x, c;
  
  	std::cin >> a >> x >> c;
 
    std::cout << a.substr(0, 1) << x.substr(0, 1) << c.substr(0, 1) << std::endl;
}