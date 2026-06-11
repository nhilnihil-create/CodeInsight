#include <bits/stdc++.h>
using namespace std;
int main()
{
	const int mods = 1000;
	int n = 0, m = 0, h = 0, w = 0;
	cin >> n >> m >> h >> w;
	if((n * m - (n / h * h) * (m / w * w)) * mods <= (n / h) * (m / w))
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i = 1; i <= n; i++, putchar('\n'))
		for(int j = 1; j <= m; j++, putchar(' '))
			printf("%d", (i % h == 0 && j % w == 0)? mods - 1 - mods * (h * w): mods);
	return 0;
}