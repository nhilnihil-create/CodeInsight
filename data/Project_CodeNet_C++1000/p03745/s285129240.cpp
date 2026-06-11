#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt, i;
	cin >> n;
	int a[n];
	bool plus, minus;

	rep(i, n) cin >> a[i];
	i = 0;
	cnt = 1;
	plus = minus = false;
	while (i < n - 1)
	{
		if (a[i] < a[i + 1])
		{
			if (minus)
			{
				cnt++;
				i++;
				minus = false;
				continue;
			}
			plus = true;
		}
		else if (a[i] > a[i + 1])
		{
			if (plus) 
			{
				cnt++;
				i++;
				plus = false;
				continue;
			}
			minus = true;
		}
		i++;
	}
	cout << cnt << endl;
	return 0;
}
