#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;
/* abc 072 - c */
int  main()
{
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int cnt = 0;
	int at = 0;
	rep(i, n)
	{
		if ((a[i] - a[at]) <= 2)
			cnt = i - at + 1;
		else
		{
			ans = max(cnt, ans);
			cnt = 1;
			while (a[i]-a[at] > 2)
				at++;
		}
	}
	ans = max(cnt, ans);
	cout << ans << endl;
	return 0;
}
