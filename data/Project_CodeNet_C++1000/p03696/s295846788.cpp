#include <iostream>
#include <string>

int main() {
	std::size_t n;
	std::string s;
	std::cin >> n >> s;
	
	int right = 0, left = 0;
	for (std::size_t i = 0; i < n; i++) {
		if (s[i] == '(') {
			left++;
		} else {
			if (left > 0) left--;
			else right++;
		}
	}
	
	std::cout << std::string(right, '(') << s << std::string(left, ')') << '\n';
	
	return 0;
}