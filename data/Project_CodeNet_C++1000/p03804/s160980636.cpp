#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;
int  main()
{
	int n, m; cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	rep(i, n)
	{
		cin >> a[i];
	}
	rep(i, m)
	{
		cin >> b[i];
	}
	int cnt = 0;
	rep(i, (n - m) + 1)
	{
		rep(j, (n - m + 1))
		{
			int k = 0;
			if (a[i].substr(j, m) == b[k])
			{
				cnt = 1;
				for(k = 1; k < m; k++)
				{
					if (a[i + k].substr(j, m) == b[k])
						cnt++;
				}
				if (cnt == m)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	// cout << cnt << endl;
	return 0;
}