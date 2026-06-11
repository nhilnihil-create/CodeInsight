#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long x, sum, cnt;
	cin >> x;
	sum = cnt = 0;
	if (x <= 6)
		cnt++;
	else
	{
		sum = x / 11;
		cnt += 2 * sum;
		sum *= 11;
		if (0 < x - sum && x - sum <= 6)
			cnt++;
		else if (6 < x - sum)
			cnt += 2;
	}
	cout << cnt << endl;
	return 0;
}
