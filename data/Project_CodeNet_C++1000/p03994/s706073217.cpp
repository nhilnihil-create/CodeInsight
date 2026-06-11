#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	string s;
	int k, now, tmp;

	cin >> s >> k;
	now = 0;
	while (now < s.size())
	{
		tmp = ('a' - s[now] + 26) % 26;
		if (tmp <= k)
		{
			k -= tmp;
			s[now] = 'a';
		}
		now++;
	}
	rep(i, k)
	{
		if (s[now - 1] == 'z')
			s[now - 1] = 'a';
		else
			s[now - 1]++;
	}
	cout << s << endl;
	return 0;
}
