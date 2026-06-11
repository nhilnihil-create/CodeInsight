#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;
#define mod 1000000007


void solve()
{
	int n, l;
	cin >> n >> l;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	string ans = v[0];
	for (int i = 1; i < n; i++)
		ans += v[i];

	cout << ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}