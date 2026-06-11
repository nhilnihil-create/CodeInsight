#include<bits/stdc++.h>
using namespace std;
int n, m, w, h, v;
int main()
{
	cin >> n >> m >> w >> h;
	if (n % w == 0 && m % h == 0)printf("No\n");
	else
	{
		printf("Yes\n");
		v = (w * h - 1) * 500 + 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				if (i % w == 0 && j % h == 0)
					printf("%d ", -v);
				else printf("500 ");
			printf("\n");
		}
	}
	return 0;
}