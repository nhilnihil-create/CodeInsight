#include<bits/stdc++.h>
using namespace std;

const char color[5] = "RYGB";

int main()
{
	int h, w, d;
	scanf("%d %d %d", &h, &w, &d);
	for(int i = 1; i <= h; ++i)
	{
		for(int j = 1; j <= w; ++j)
		{
			int x = (i + j + 500) / d;
			int y = (i - j + 500) / d;
			printf("%c", color[((x & 1) << 1) + (y & 1)]);
		}
		puts("");
	}
	return 0;
}