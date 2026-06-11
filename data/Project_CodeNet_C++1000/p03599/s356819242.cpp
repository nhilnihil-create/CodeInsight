#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b, c, d, e, f;
	int ans_w, ans_s;
	double mx;
	set<int> water, suger;

	cin >> a >> b >> c >> d >> e >> f;
	for(int i = 0; i <= 30; i++) for (int j = 0; j <= 30; j++)
	{
		int x = i * 100 * a + j * 100 * b;
		if (x <= f)
		{
			water.insert(x);
		}
	}	
	for(int i = 0; i <= f; i++) for (int j = 0; j <= f; j++)
	{
		int y = i * c + j * d;
		if (y <= f)
		{
			suger.insert(y);
		}
	}
	mx = 0;
	ans_w = ans_s = 0;
	for(int w : water)
	{
		for(int s : suger)
		{
			if ((double)w * e / 100 >= s)
			{
				int sum = w + s;
				if (sum <= f && (double)100 * s / (w + s) >= mx)
				{
					mx = (double)100 * s / (w + s);
					ans_w = sum;
					ans_s = s;
				}
			}
		}
	}
	cout << ans_w << " " << ans_s << endl;
	return 0;
}
