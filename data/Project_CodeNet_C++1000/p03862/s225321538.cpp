#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] + a[i-1] > x)
		{
			if(a[i] + a[i-1] > x)
			{
				if(a[i-1] <= x)
				{
					ans += a[i] + a[i-1] - x;
					a[i] = x - a[i-1];
				}
				else
				{
					ans += a[i];
					a[i] = 0;
					ans += a[i-1] - x;
					a[i-1] = x;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}