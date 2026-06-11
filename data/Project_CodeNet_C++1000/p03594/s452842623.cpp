#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
	char c[5] = "RYGB";
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++, putchar('\n'))
		for (int j = 1; j <= m; j++)
			putchar(c[2 * ((i + j + m) / k & 1) + ((i - j + m) / k & 1)]);
	
	return 0;
}