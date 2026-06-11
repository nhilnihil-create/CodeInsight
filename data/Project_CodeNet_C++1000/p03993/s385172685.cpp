#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt;
	cin >> n;
	int a[n];
	map<int, int> mp;
	rep(i, n)
	{
		cin >> a[i];
		a[i]--;
		mp[i] = a[i];
	}
	cnt = 0;
	rep(i, n)
	if (mp[mp[i]] == i)
		cnt++;
	cout << cnt / 2 << endl;
	return 0;
}
