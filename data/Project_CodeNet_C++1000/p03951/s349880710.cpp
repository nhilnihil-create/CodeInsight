#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans;
	string s, t;
	cin >> n >> s >> t;
	ans = 2 * n;
	rep(i, s.size())
	{
		if (s.substr(i, s.size() - i) == t.substr(0, s.size() - i))
		{
			ans = n + t.size() - (s.size() - i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
