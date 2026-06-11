#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;
using Pl = pair<ll,ll>;

ll N, K, ans;

int main()
{
	cin >> N >> K;
	vector<ll>a(N), v(N + 1);
	rep(i, N)
	{
		cin >> a[i];
		v[i + 1] = a[i];
	}
	rep(i, N) v[i + 1] = max(v[i + 1], v[i]);
	ans = 112345678901;
	rep(bit, (1ll << N))
	{
		vector<ll>idxs;
		rep(i, N)
		{
			if (bit>>i&1ll) idxs.push_back(i);
		}
		if (idxs.size() != K) continue;
		ll maxH = 0, res = 0;
    for (int i : idxs)
		{
			maxH = max(maxH, v[i]);
			if (a[i] <= maxH)
			{
				++maxH;
				res += maxH - a[i];
			}
			else maxH = a[i];
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
