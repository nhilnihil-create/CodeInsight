#include <iostream>

int main() {
	int n, k, x, y;
  	int res;
  
  	std::cin >> n >> k >> x >> y;
  
  	if (k < n) {
      res = k * x + (n - k) * y;
    } else {
      res = n * x;
    }
  
  	std::cout << res << std::endl;
}