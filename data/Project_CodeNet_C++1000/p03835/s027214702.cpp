#include<iostream>
using namespace std;


int main()
{
	int s, k, ans;
	ans = 0;
	cin >> k >> s;
	for (int x = 0; x <= k; x++)
	{
		for (int y = x; y <= k; y++)
		{
			for (int z = y; z <= k; z++)
			{
				if (x + y + z == s)
				{
					if (x < y && y<z) { ans += 6; }
					if ((x < y) && (y == z)) { ans += 3; }
					if ((x == y) && (y < z)) { ans += 3; }
					if (x == y && y== z) { ans += 1; }
				}

			}

		}
	}
	cout << ans;
	return 0;
}