#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	int ans = 0;
	int at = 0;
	for(int i = 0; i < n; i++)
	{
		if (a[i] - a[at] <= 2)
		{
			cnt = (i - at) + 1;
		}
		else
		{
			ans = max(cnt, ans);
			cnt = 1;
			while (abs(a[at]- a[i]) > 2)
				at++;
		}
		// cout << cnt << endl;
	}
	ans = max(cnt, ans);
	// cout << endl;
	cout << ans << endl;
	return 0;
}