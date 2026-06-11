#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int n, a, b;
int h[maxn];
bool check(ll mid)
{
	ll ret = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(h[i] <= mid * b) continue;
		ret += (h[i] - mid * b + a - 1) / a;
	}
	return ret <= mid;
}	
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	a -= b;
	for(int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	int l = 1, r = 1e9;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}