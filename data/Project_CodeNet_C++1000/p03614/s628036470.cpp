#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 27;

int main()
{
	int n, a[N], ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
                           
	for (int i = 1; i < n; i++)
	{
		if (a[i] == i)
		{
			swap(a[i], a[i + 1]);
			ans++;
		}
	}

	if (a[n] == n)
		ans++;

	cout << ans;
		
	return 0;
}