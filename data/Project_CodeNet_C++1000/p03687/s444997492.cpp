#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t, u;
	bool ok, flag;
	int ans, cnt;

	cin >> s;
	ans = s.size();
	flag = true;
	rep(i, s.size() - 1)
	{
		if (s[i] != s[i + 1])
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << 0 << endl;
		return 0;
	}
	rep(i, 26)
	{
		t = s;
		char c = i + 'a';
		ok = false;
		while (!ok)
		{
			ok = true;
			u = "";
			rep(j, t.size() - 1)
			{
				if (t[j] == c || t[j + 1] == c) 
					u += c;
				else
				{
					u += t[j];
					ok = false;
				}
			}
			t = u;
		}
		cnt = s.size() - t.size();
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
