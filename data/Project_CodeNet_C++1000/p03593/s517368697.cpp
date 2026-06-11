#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int h, w;
	int g1, g2, g4;
	cin >> h >> w;
	vector<int> mp(26);
	rep(i, h) rep(j, w)
	{
		char c;
		cin >> c;
		mp[c - 'a']++;
	}
	g1 = 0;
	g2 = 0;
	g4 = (h / 2) * (w / 2);
	if (h % 2 == 0 || w % 2 == 0)
	{
		if (!(h % 2 == 0 && w % 2 == 0))
			g2 = (h % 2 == 0 ? h : w) / 2;
	}
	else
	{
		g1 = 1;
		g2 = (h / 2) + (w / 2);
	}

	rep(i, 26)
	{
		int v = mp[i];
		while (g4 > 0 && v >= 4)
		{
			v -= 4;
			g4--;
		}
		while (g2 > 0 && v >= 2)
		{
			v -= 2;
			g2--;
		}
		while (g1 > 0 && v >= 1)
		{
			v--;
			g1--;
		}
		if (v > 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
