#include <iostream>

int main()
{
	int A, B, C;
	std::cin >> A >> B >> C;
	bool isSame = false;
	int cnt = 0;
	while ((A&1)==0 && (B&1)==0 && (C&1)==0) {
		if (A==B && B==C) { isSame = true; break; }
		int a = B/2 + C/2;
		int b = A/2 + C/2;
		int c = A/2 + B/2;
		A = a; B = b; C = c;
		cnt++;
	}
	if (!isSame) std::cout << cnt << std::endl;
	else std::cout << -1 << std::endl;
	return 0;
}
