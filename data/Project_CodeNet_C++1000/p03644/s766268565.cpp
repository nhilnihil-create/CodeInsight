#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int res = 1;
	for (; res<=N; res*=2);
	std::cout << res/2 << std::endl;
	return 0;
}
