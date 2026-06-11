#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "********************************************\n"
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL)
ll l[1000006], r[1000006], a[1000006], n;
ll solve()
{
	stack<ll> s;
	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && a[i] <= a[s.top()])
		{
			r[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty())
	{
		r[s.top()] = n - 1;
		s.pop();
	}
	for (int i = n - 1; i >= 0; --i)
	{
		while (!s.empty() && a[i] <= a[s.top()])
		{
			l[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty())
	{
		l[s.top()] = 0;
		s.pop();
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll mul = (r[i] - i + 1) * (i - l[i] + 1);
		ans += mul * a[i];
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	fast;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = solve();
	
	
	cout << ans;
	return 0;
}