#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll n;
ll f(vector<ll> sum, bool flag)
{
	ll cnt, tmp;

	if (flag)
		sum[0] = -1;
	else
		sum[0] = 1;
	cnt = tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] += tmp;
		if (sum[i] * sum[i - 1] >= 0)
		{
			if (sum[i] == 0)
			{
				if (sum[i - 1] < 0)
				{
					sum[i] = 1;
					tmp += 1;
				}
				else
				{
					sum[i] = -1;
					tmp += -1;
				}
				cnt++;
			}
			else if (sum[i] < 0)
			{
				tmp += 1 - sum[i];
				cnt += abs(1 - sum[i]);
				sum[i] = 1;
			}
			else if (sum[i] > 0)
			{
				tmp += -1 * (1 + sum[i]);
				cnt += abs(-1 * (1 + sum[i]));
				sum[i] = -1;
			}
		}
	}
	return cnt;
}

signed main(void)
{
	cin >> n;
	vector<ll> s(n + 1, 0);
	ll ans;

	for (int i = 1; i <= n; i++)
		cin >> s[i];
	rep(i, n) s[i + 1] += s[i];
	ans = f(s, true);
	ans = min(ans, f(s, false));
	cout << ans << endl;
	return 0;
}
