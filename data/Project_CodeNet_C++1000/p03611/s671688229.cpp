#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	int n; cin >> n;
	vector <int> a(n);
	set <int> st;
	map<int, int> mp;
	rep(i, n)
	{
		cin >> a[i];
		mp[a[i]]++;
		mp[a[i]-1]++;
		mp[a[i]+1]++;
	}
	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, mp[a[i]]);
		ans = max(ans, mp[a[i]-1]);
		ans = max(ans, mp[a[i]+1]);
	}
	cout << ans << endl;
	return 0;
}
