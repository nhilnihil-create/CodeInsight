#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x, y;
	cin >> x >> y;
	
	if (abs(x) == abs(y))
	{
		if (x > 0 && y < 0)
			printf("1\n");
		else if (x < 0 && y > 0)
			printf("1\n");
		else
			printf("0\n");
	}
	else if (abs(x) < abs(y))
	{
		int ans = 0;
		if (x < 0)
			ans++;
		ans += abs(y) - abs(x);
		if (y < 0)
			ans++;
		printf("%d\n", ans);
	}
	else
	{
		int ans = 0;
		if (x > 0)
			ans++;
		ans += abs(x) - abs(y);
		if (y > 0)
			ans++;
		printf("%d\n", ans);
	}

	return 0;
}
