#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <fstream>

using namespace std;

int H,W,h,w;

int main()
{
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if (H % h == 0 && W % w == 0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i = 1;i <= H;i++,printf("\n"))
		for (int j = 1;j <= W;j++)
			printf("%d ",i % h == 0 && j % w == 0 ? -h * w * 1000 + 999 : 1000);
	return 0;
}