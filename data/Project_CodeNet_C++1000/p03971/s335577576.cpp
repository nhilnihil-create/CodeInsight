#include <iostream>

int main()
{
	int N, A, B;
	std::cin >> N >> A >> B;
	int qualifiers = 0;
	int int_order = 0;
	for (int i=1; i<=N; i++) {
		char c;
		std::cin >> c;
		if (c == 'a') {
			if (qualifiers < A+B) {
				std::cout << "Yes" << std::endl;
				qualifiers++;
			}
			else std::cout << "No" << std::endl;
		}
		else if (c == 'b') {
			if (qualifiers < A+B && int_order < B) {
				std::cout << "Yes" << std::endl;
				qualifiers++;
				int_order++;
			}
			else std::cout << "No" << std::endl;
		}
		else std::cout << "No" << std::endl;
	}
	return 0;
}
