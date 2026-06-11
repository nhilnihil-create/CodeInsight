#include <iostream>
#include <string>

int main()
{
	int n, a, b;
	std::string s;
	std::cin >> n >> a >> b >> s;
	
	int cnt = 0;
	int bcnt = 0;
	const int max = a + b;
	for (char c : s) {
		if (c == 'b') bcnt++;
		if (cnt >= max || c == 'c' || (c == 'b' && bcnt > b)) {
			std::cout << "No\n";
		}
		else {
			std::cout << "Yes\n";
			cnt++;
		}
	}
	
	return 0;
}
