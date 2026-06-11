#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define endl "\n"

bool vis[10];

int32_t main()
{
	IOS;
	int n, k, dig	;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> dig;
		vis[dig] = 1;
	}

	int ans;
	for (ans = n;; ans++)
	{
		int cur = ans;
		while (cur > 0)
		{
			if (vis[cur % 10])
				break;
			cur /= 10;
		}
		if (cur == 0)
			break;
	}
	cout << ans << endl;

	return 0;
}