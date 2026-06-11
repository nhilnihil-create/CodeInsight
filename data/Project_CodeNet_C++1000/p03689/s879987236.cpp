#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int mx, my, nx, ny;
	scanf("%d%d%d%d", &mx, &my, &nx, &ny);
	if (mx%nx == 0 && my%ny == 0)printf("No\n");
	else
	{
		printf("Yes\n");
		for (int i = 0; i < mx; i++)
		{
			for (int j = 0; j < my; j++)
			{
				if (mx%nx != 0)
				{
					if (i%nx == 0)printf("999999999 ");
					else if (i%nx == nx - 1)printf("-1000000000 ");
					else printf("0 ");
				}
				else
				{
					if (j%ny == 0)printf("999999999 ");
					else if (j%ny == ny - 1)printf("-1000000000 ");
					else printf("0 ");
				}
			}
			printf("\n");
		}
	}
}