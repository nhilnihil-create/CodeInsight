#include <iostream>

int main() {
	int a, b, c;
  	std::string res;
  
  std::cin >> a >> b >> c;
  
  if ( a == (b+c) || b == (c+a) || c == (a + b)) {
  	res = "Yes";
  } else {
  	res = "No";
  }
  
  std::cout << res << std::endl;
}