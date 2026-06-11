#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int ans = 1, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = i; j % 2 == 0; j /= 2)
		{
			tmp++;
		}

		if (cnt < tmp)
		{
			ans = i;
			cnt = tmp;
		}
	}

	cout << ans << endl;

	return 0;
}