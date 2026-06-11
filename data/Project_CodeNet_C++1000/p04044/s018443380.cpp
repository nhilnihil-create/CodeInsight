#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int int64_t
#define ll long long

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> str;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
	}
}

int32_t main()
{

	// int test;
	// cin >> test;
	// while (test--)
	{
		solve();
	}
	return 0;
}