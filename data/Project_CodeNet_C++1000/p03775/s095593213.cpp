#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int get(int x)
{
	int cnt = 0;
	while(x > 0)
	{
		cnt++;
		x /= 10;
	}
	return cnt;
}

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	int ans = 1e9;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			ans = min(ans, max(get(i), get(n / i)));
		}
	}
	cout << ans;
	return 0;
}