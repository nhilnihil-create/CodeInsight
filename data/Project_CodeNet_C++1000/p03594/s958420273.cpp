#include <cstdio>
#define R register
using namespace std;
int main(void)
{
	int n, m, blk, x, y; char c;
	scanf("%d%d%d", &n, &m, &blk);
	for (R int i = 1; i <= n; ++i)
	{
		for (R int j = 1; j <= m; ++j)
		{
			x = (i + j + m) / blk % 2, y = (i - j + m) / blk % 2;
			printf("%c", "YBGR"[2 * x + y]);
		}
		putchar(10);
	}

}