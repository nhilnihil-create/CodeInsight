#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt;
	cin >> n;
	vector<int> a(n);
	long long sum[n];
	bool flag[n];

	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	rep(i, n) sum[i] = a[i];
	rep(i, n - 1) sum[i + 1] += sum[i];
	rep(i, n) flag[i] = true;
	cnt = 0;
	rep(i, n - 1)
	{
		if (sum[i] * 2 < a[i + 1])
			flag[i] = false;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if (flag[i])
			cnt++;
		else
			break;
	}
	cout << cnt << endl;
	return 0;
}
