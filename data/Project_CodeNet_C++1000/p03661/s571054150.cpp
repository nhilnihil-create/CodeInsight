#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, sum = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int ans = 1e18;
	int cur = 0;
	for(int i = 1; i <= n - 1; i++)
	{
		cur += a[i];
		ans = min(ans, abs(cur - (sum - cur)));
	}
	cout << ans;
	return 0;
}