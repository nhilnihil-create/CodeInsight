#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
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
const int N = 1e5;

int n;
int a[N + 2], ans;

inline bool compare(int x, int y)
{
	return x > y;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1, compare);

	for (int i = 0; i <= n; i++) {
		if (i + 1 > a[i + 1]) {
			for (int j = i + 1; a[j] == i; j++)
				ans ^= 1;
			ans |= (a[i] - i) & 1;
			if (ans)
				printf("First\n");
			else
				printf("Second\n");
			break;
		}
	}

	return 0;
}
