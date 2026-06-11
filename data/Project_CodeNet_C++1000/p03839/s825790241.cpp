#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e18 + 9;
int a[N], pre[N], suf[N], sum[N];

signed main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];

		if(a[i] > 0)
			pre[i] = pre[i - 1] + a[i];
		else
			pre[i] = pre[i - 1];
	}

	for(int i = n; i >= 1; i--)
	{
		if(a[i] > 0)
			suf[i] = suf[i + 1] + a[i];
		else
			suf[i] = suf[i + 1];
	}

	int ans = -inf;
	for(int l = 1; l + k - 1 <= n; l++)
	{
		int r = l + k - 1;

		int res = max(sum[r] - sum[l - 1], 0LL) + pre[l - 1] + suf[r + 1];
		ans = max(ans, res);
	}

	cout << ans;
}