#include <iostream>
 
int main () {
	int a,b,c;
  
  std::cin >> a >> b >> c;
  std::string res;
  
  if (c-b == b-a) {
  	res = "YES";
  } else {
  	res = "NO";
  }
  
  std::cout << res << std::endl;
}
