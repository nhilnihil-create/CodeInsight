#include <iostream>
using namespace std;
int main() {

	//A
	int n;
	cin >> n;
	char s[100];
	char t[100];

	cin >> s;
	cin >> t;

	int i, j;
	int flag;
	for (i = 0; i < n; i++) {
		flag = 0;
		for (j = 0; j <= n-i-1; j++) {
			if (t[j] == s[j + i]) {

			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << n + i;
			return 0;
		}
	}
	cout << 2 * n;
	return 0;

	/*int n, x, i;
	
	std::cin >> n;
	std::cin >> x;

	
	if (n == 1) {
		if (x == 1) {
			std::cout << "Yes\n";
			std::cout << 1;
		}
		else {
			std::cout << "No";
		}
	}
	else if (n == 2) {
		if (x == 2) {
			std::cout << "Yes\n";
			std::cout << 1; std::cout << "\n"; std::cout << 2; std::cout << "\n"; std::cout << 3;
		}
		else {
			std::cout << "No";
		}
	}
	else {
		if (x == 1) {
			std::cout << "No";
		}
		else if (x == 2 * n - 1) {
			std::cout << "No";
		}
		else if (x == 2) {
			std::cout << "Yes\n";
			for (i = 1; i <= 2 * n - 1; i++) {
				if (i < n - 1) {
					std::cout << i + 4;
				}
				else if (i < n + 2) {
					std::cout << n + 2 - i;
				}
				else if (i == n + 2) {
					std::cout << 4;
				}
				else {
					std::cout << i;
				}
			}
			std::cout << "\n";
		}
		else {
			std::cout << "Yes\n";
			for (i = 1; i <= 2 * n - 1; i++) {
				if (i == n - 1) {
					std::cout << x - 1;
				}
				else if (i == n) {
					std::cout << x;
				}
				else if (i == n + 1) {
					std::cout << x + 1;
				}
				else if (i == n + 2) {
					std::cout << x - 2;
				}
				//else if (i == x - 1) {
				//	std::cout << n - 1;
				//}
				//else if (i == x) {
				//	std::cout << n;
				//}
				//else if (i == x + 1) {
				//	std::cout << n + 1;
				//}
				//else if (i == x - 2) {
				//	std::cout << n + 2;
				//}
				else {
					std::cout << i;
				}
				std::cout << "\n";
			}
		}
	}
	return 0;
	*/

}