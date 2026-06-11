#include <iostream>

 int main() {

	 int x;
	 int a = 1;
	 std::cin >> x;
	 
	 while (x > 0) {
		 x -= a;
		 a += 1;
	 }
	 std::cout << a - 1 << std::endl;

	 return 0;
}