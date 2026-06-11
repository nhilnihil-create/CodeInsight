#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> as(n);
	for (auto &&a : as)
	{
		cin >> a;
		a--;
	}

	vector<bool> done(n, false);
	for (int x = 0, cnt = 0; !done[x]; cnt++, x = as[x])
	{
		if (x == 1)
		{
			cout << cnt << endl;
			return 0;
		}

		done[x] = true;
	}

	cout << -1 << endl;

	return 0;
}