#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a + b + c == 17)
	{
		if (a + b == 10)
		{
			if (a == 5)
				printf("YES\n");
			else printf("NO\n");
		}
		else if (a + b == 12)
		{
			if (a == 5 || a == 7)
				printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	else printf("NO\n");
	
	return 0;
}