#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m;
	cin >> n >> m;
	int x[m], y[m];
	int have[n];
	bool b[n];
	rep(i, m) 
	{
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
	}
	rep(i, n) 
	{
		have[i] = 1; 
		b[i] = false;
	}
	b[0] = true;	
	rep(i, m)
	{
		if (b[x[i]])
			b[y[i]] = true;
		have[x[i]]--;
		have[y[i]]++;
		if (have[x[i]] <= 0)
			b[x[i]] = false;
	}
	int cnt = 0;
	rep(i, n)
	{
		if (b[i])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
