#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
#define maxn 30
char a[maxn][maxn][5];
int main()
{
	int h, w;
	cin >> h >> w;
	
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%s",a[i][j]);
			if (strcmp("snuke", a[i][j]) == 0)
			{
				printf("%c%d\n", j - 1 + 'A', i); break;
			}
				

		}
	}
	


	return 0;
}