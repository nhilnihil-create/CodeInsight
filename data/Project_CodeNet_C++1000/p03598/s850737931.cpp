#include <iostream>
#include <utility>

int main()
{
	int n, k;
	std::cin >> n >> k;
	
	int x;
	int a, b;
	int d = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		a = x * 2;
		b = (k - x) * 2;
		d += std::min(a, b);
	}
	
	std::cout << d << std::endl;
	
	return 0;
}
