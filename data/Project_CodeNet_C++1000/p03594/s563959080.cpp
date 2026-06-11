#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int H,W,d;
int x;
char c[5] = "RYGB";

int main()
{
	scanf("%d%d%d",&H,&W,&d);
	for(int i = 1;i <= H; ++ i)
	{
		for(int j = 1;j <= W; ++ j)
		{
			int x = (W + i + j) / d % 2;
			int y = (W + i - j) / d % 2;
			printf("%c",c[x * 2 + y]);
		}
		printf("\n");
	}
}