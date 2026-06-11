#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	long long cnt;
	cin >> n;
	pair<long long, long long> x[n];

	cnt = 0;
	rep(i, n) cin >> x[i].first >> x[i].second;
	for(int i = n - 1; i >= 0; i--)
	{
		x[i].first += cnt;
		if (x[i].first % x[i].second != 0)
			cnt += x[i].second * (x[i].first / x[i].second + 1) - x[i].first;
	}
	cout << cnt << endl;
	return 0;
}
