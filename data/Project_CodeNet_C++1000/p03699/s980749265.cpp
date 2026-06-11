#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;

int  main()
{
	int n;
	cin >> n;
	vector<int> s(n);
	int sum = 0;
	int ans;
	rep(i, n)
	{
		cin >> s[i];
		sum += s[i];
	}
	if (sum % 10)
		ans = sum;
	else
	{
		sort(s.begin(), s.end());
		rep(i, n)
		{
			if (s[i] % 10)
			{
				ans = sum - s[i];
				break;
			}
		}
		if (!ans)
			ans = 0;
	}
	cout << ans << endl;
	return (0);
}
