#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt;
	cin >> n;
	vector<int> a(n);
	cnt = 0;
	rep(i, n) 
	{
		cin >> a[i];
		if (a[i] % 2 != 0)
			cnt++;
	}
	if (cnt % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl; 
	return 0;
}
