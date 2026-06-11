#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	int n;

	cin >> s;
	n = s.size();
	t = s;
	reverse(t.begin(), t.end());
	rep(i, n)
	{
		if (t[i] == 'p')
			t[i] = 'q';
		else if (t[i] == 'q')
			t[i] = 'p';
		else if (t[i] == 'b')
			t[i] = 'd';
		else if (t[i] == 'd')
			t[i] = 'b';
	}
	if (s == t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
