#include <iostream>

int main() {
	int a,b, res;
  	std::string op;
  
  	std::cin >> a >> op >> b;
      
    if (op == "+") {
    	res = a + b;
    } else {
    	res = a - b;
    }
  
  std::cout << res << std::endl;
}