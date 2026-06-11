#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int k, s;

void solve()
{
	int c = 0;
	for (int x = 0; x <= k; ++x)
	{
		for (int y = 0; y <= k; ++y)
		{
			int z = s - x - y;
			if (0 <= z && z <= k)
				c++;
		}
	}
	cout << c << endl;
}

int main()
{
	cin >> k >> s;
	solve();
}
