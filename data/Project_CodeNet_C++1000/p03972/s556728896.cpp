#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<long> ps(h), qs(w), accp(h+1), accq(w+1);
	for (int i = 0; i < h; i++) cin >> ps[i];
	for (int i = 0; i < w; i++) cin >> qs[i];
	sort(ps.begin(), ps.end());
	sort(qs.begin(), qs.end());
	for (int i = 0; i < h; i++)
	{
		accp[i + 1] = accp[i] + ps[i];
	}
	for (int i = 0; i < w; i++)
	{
		accq[i + 1] = accq[i] + qs[i];
	}
	long ans = accp[h] + accq[w] * (h + 1);
	for (int i = 0; i < w; i++)
	{
		int l = -1, r = h;
		while(l+1<r)
		{
			int m = (l + r) / 2;
			(qs[i] >= ps[m] ? l : r) = m;
		}
		ans -= (l + 1) * qs[i] - accp[l + 1];
	}
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
