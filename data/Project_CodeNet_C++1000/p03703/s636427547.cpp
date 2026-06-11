#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e15;
const int mod = 998244353;//1e9 + 7;//786433;
const double Pi = acos(-1);

void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, k;
long long a[200005];
long long ans = 0;
long long BIT[200005];
vector <long long> Val;

void Update(int node, long long val)
{
	for(node; node <= n + 1; node += node & -node)
	{
		BIT[node] += val;
	}
}

long long Get(int node)
{
	long long ans = 0;
	for(node; node > 0; node -= node & -node)
	{
		ans += BIT[node];
	}
	return ans;
}

signed main()
{
	Fastio();
	cin >> n >> k;
	Val.eb(0);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= k;
		a[i] += a[i - 1];
		Val.eb(a[i]);
	}
	sort(Val.begin(), Val.end());
	for(int i = 0; i <= n; i++)
	{
		a[i] = lower_bound(Val.begin(), Val.end(), a[i]) - Val.begin() + 1;
	}
	for(int i = 0; i <= n; i++)
	{
		ans += Get(a[i]);
		Update(a[i], 1);
	}
	cout << ans;
}