#include <iostream>
#include <cstdio>

int main()
{
	int H, W, h, w; scanf("%d%d%d%d", &H, &W, &h, &w);
	int a = 4000, b = -(h * w - 1) * a - 1;
	if(H % h == 0 && W % w == 0) return 0 * puts("No");
	puts("Yes");
	for(int i = 1; i <= H; i++, puts(""))
		for(int j = 1; j <= W; j++)
		{
			if(i % h == 0 && j % w == 0) printf("%d ", b);
			else printf("%d ", a);
		}
}