#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
inline int read()
{
	int f = 1, x = 0;
	char ch;

	do{
		ch = getchar();
		if (ch == '-')
			f = -1;
	}while(ch < '0' || ch > '9');
	do{
		x = x * 10 + ch - '0';
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return f * x;
}

int a, b, c;

int main()
{
	a = read();
	b = read();
	c = read();

	if ((a == 5 && b == 5 && c == 7) || (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
