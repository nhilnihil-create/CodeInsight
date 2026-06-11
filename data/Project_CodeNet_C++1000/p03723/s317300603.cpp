#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	
	int i = 0;
	int na, nb, nc;
	while (!(a % 2 || b % 2 || c % 2)) {
		i++;
		if (i > 114514) {
			i = -1;
			break;
		}
		
		na = (b + c) / 2;
		nb = (a + c) / 2;
		nc = (a + b) / 2;
		
		a = na;
		b = nb;
		c = nc;
	}
	
	std::cout << i << std::endl;
	
	return 0;
}
