#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N = 100005;

int n,m,A[MAX_N];
map<int, pair<ll, ll>> sum;

// x[a..b]++ und add[a..b] += c
void magic(int a, int b, int c)
{
	if (a > b)
		return;
	sum[a].first++;
	sum[b+1].first--;
	sum[a].second += c;
	sum[b+1].second -= c;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",A+i);
	ll cost = 0;
	for (int i=1; i<n; i++)
	{
		int a = A[i], b = A[i+1];
		cost += (b-a+m)%m;
		if (a <= b)
			magic(a+1, b, -a-1); // a < x <= b: x - a - 1
		else
		{
			magic(a+1, m, -a-1); // a < x <= m:  x - a - 1
			magic(1, b, m-a-1);  // 1 <= x <= b: m - a + x - 1
		}
	}
	ll sub = 0, px = 0, padd = 0;
	for (auto it : sum)
	{
		sub = max(sub, (it.first-1)*px + padd);
		px += it.second.first;
		padd += it.second.second;

	}
	printf("%lld\n", cost - sub);
	return 0;
}