#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, c, k;
	cin >> n >> c >> k;
	long t[n];
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	sort(t, t + n);

	long now;
	int i = 0;
	int res = 0;
	while (i < n)
	{
		int j = min(i + c, n);
		while (t[j - 1] - t[i] > k)
		{
			j--;
		}
		res++;
		i = j;
	}

	cout << res << endl;
	return 0;
}
