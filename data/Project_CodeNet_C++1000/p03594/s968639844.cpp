#include <cstdio>
int main()
{
	// freopen("CF17-QA-D.in", "r", stdin); 
	int n, m, d; 
	scanf("%d%d%d", &n, &m, &d); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			putchar("RYGB"[((i + j) / d & 1) << 1 | ((i + m - j) / d & 1)]); 
		puts(""); 
	}
	return 0; 
}
