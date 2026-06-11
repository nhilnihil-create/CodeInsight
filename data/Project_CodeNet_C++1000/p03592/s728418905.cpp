#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;

signed main(void)
{
	int n, m, K;
	cin >> n >> m >> K;
	rep(k, n)
	{
		rep(l, m)
		{
			if (k * (m - l) + (n - k) * l == K)
			{
				cout << "Yes" << endl;
				return 0;
			}	
		}
	}
	cout << "No" << endl;
	return 0;
}
