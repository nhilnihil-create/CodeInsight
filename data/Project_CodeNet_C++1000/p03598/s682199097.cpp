#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> as(n);
	for (auto &&a : as)
	{
		cin >> a;
	}

	int ans = 0;
	for (auto &&a : as)
	{
		ans += 2 * min(a, k - a);
	}

	cout << ans << endl;

	return 0;
}