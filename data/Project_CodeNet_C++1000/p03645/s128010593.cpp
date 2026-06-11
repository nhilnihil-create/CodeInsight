#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int  main()
{
	int n, m;
	cin >> n >> m;
	set<int> reach;
	vector<pair<int, int> > p(m);
	rep(i, m)
	{
		cin >> p[i].first >> p[i].second;
		if (p[i].second == n)
			reach.insert(p[i].first);
	}
	rep(i, m)
	{
		if (p[i].first == 1)
		{
			if (reach.count(p[i].second))
			{
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return (0);
}
