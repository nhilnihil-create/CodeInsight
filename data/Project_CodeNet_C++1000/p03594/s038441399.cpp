#include <cstdio>
using namespace std;
char s[] = "RGYB";
int n, m, k;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; putchar(10), i++)
		for (int j = 0; j < m; j++)
			putchar(s[(i + j) / k % 2 * 2 + (i + m - j) / k % 2]);
}