#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int  main()
{
	int n, k; cin >> n >> k;
	vector<int> v(n);
	rep(i, n)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	int ans = 0;
	rep(i, k)
		ans += v[i];
	cout << ans << endl;
	return (0);
}
