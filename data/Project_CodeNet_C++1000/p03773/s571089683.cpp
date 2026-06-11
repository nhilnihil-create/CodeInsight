#include <iostream>

int main()
{
	int A;
	int B;

	std::cin >> A >> B;

	int answer = (A + B) % 24;
	std::cout << answer;

	return 0;
}
