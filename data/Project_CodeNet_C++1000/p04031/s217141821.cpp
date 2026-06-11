#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define endl "\n"

const int N = 105;
int a[N];
unordered_map<int, int>m;

int check(int y)
{
	int ans = 0;
	for (auto x : m)
	{
		int val = (x.ff - y) * (x.ff - y);
		ans += x.ss * val;

	}
	return ans;
}

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	for (auto x : m)
		sum += x.ff;
	int y = sum / (int)m.size();
	int res = 2e9;
	for (int i = y - 105; i <= y + 105; i++)
	{
		res = min(res, check(i));
	}
	cout << res << endl;

	return 0;
}