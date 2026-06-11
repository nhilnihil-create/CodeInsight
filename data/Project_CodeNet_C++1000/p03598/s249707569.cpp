#include <iostream>

int main()
{
	int N, K;
	int X[100];
	std::cin >> N;
	std::cin >> K;
	for (int i=0; i<N; i++) std::cin >> X[i];
	int res = 0;
	for (int i=0; i<N; i++) res += 2 * std::min(X[i], K-X[i]);
	std::cout << res << std::endl;
	return 0;
}
