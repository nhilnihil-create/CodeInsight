#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, l, out_l, out_r;
	string s;
	cin >> n >> s;

	l = out_l = out_r = 0;
	rep(i, n)
	{
		if (s[i] == ')')
		{
			if (out_r > 0)
				out_r--;
			if (l == 0) 
				out_l++;
			else
				l--;
		}
		else if(s[i] == '(')
		{
			l++;
			out_r++;
		}
	}
	rep(i, out_l)
		cout << '(';
	cout << s;
	rep(i, out_r)
		cout << ')';
	cout << endl;
}
