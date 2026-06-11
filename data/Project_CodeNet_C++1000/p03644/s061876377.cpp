#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int result;
	for (result = 1; result <= n; result *= 2);
	
	std::cout << result / 2 << std::endl;
	
	return 0;
}
