#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<long> ps(h), qs(w), accp(h+1), accq(w+1);
	for (int i = 0; i < h; i++) cin >> ps[i];
	for (int i = 0; i < w; i++) cin >> qs[i];
	long psum = 0, qsum = 0;
	sort(ps.begin(), ps.end());
	sort(qs.begin(), qs.end());
	for (int i = 0; i < h; i++)
	{
		psum += ps[i];
		accp[i + 1] = accp[i] + ps[i];
	}
	for (int i = 0; i < w; i++)
	{
		qsum += qs[i];
		accq[i + 1] = accq[i] + qs[i];
	}
	long res1 = psum+qsum*(h+1), res2 = qsum+psum*(w+1);
	for (int i = 0; i < h; i++)
	{
		int l = -1, r = w;
		while(l+1<r)
		{
			int m = (l + r) / 2;
			(ps[i] >= qs[m] ? l : r) = m;
		}
		res2 -= (l + 1) * ps[i] - accq[l + 1];
	}
	for (int i = 0; i < w; i++)
	{
		int l = -1, r = h;
		while(l+1<r)
		{
			int m = (l + r) / 2;
			(qs[i] >= ps[m] ? l : r) = m;
		}
		res1 -= (l + 1) * qs[i] - accp[l + 1];
	}
	cout << min(res1, res2) << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
