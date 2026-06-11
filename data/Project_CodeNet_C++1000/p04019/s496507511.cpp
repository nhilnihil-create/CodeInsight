#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	map<char, int> mp;
	bool ok;

	cin >> s;
	mp['N'] = 0;
	mp['W'] = 0;
	mp['S'] = 0;
	mp['E'] = 0;
	rep(i, s.size()) mp[s[i]]++;
	ok = true;
	if (mp['N'] > 0)		
	{
		if (mp['S'] <= 0)
			ok = false;
	}
	if (mp['S'] > 0)		
	{
		if (mp['N'] <= 0)
			ok = false;
	}
	if(mp['W'] > 0)
	{
		if(mp['E'] <= 0)
			ok = false;
	}
	if (mp['E'] > 0)		
	{
		if (mp['W'] <= 0)
			ok = false;
	}
	if(ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
