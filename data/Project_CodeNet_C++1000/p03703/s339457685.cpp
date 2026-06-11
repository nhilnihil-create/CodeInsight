#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[200001], p[200001];
                            
int bit[200001];
void upd(int u)
{
	for (; u <= 200000; u += u & (-u))
		bit[u]++;			
}

int query(int u)
{
	int ans = 0;
	for (; u > 0; u -= u & (-u))
		ans += bit[u];
	return ans;			
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	vector<int> val_p = {-1000000000000000000LL, 0LL};
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= k;
		p[i] = p[i - 1] + a[i];
		val_p.push_back(p[i]);
	}
	sort(val_p.begin(), val_p.end());
	val_p.resize(unique(val_p.begin(), val_p.end()) - val_p.begin());
	upd(lower_bound(val_p.begin(), val_p.end(), p[0]) - val_p.begin());
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(val_p.begin(), val_p.end(), p[i]) - val_p.begin();
		ans += query(pos);
		upd(pos);			
	}
	cout << ans;
}