#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<long,long>;
typedef long long ll;

int  main()
{
	long N,M;
	cin >> N >> M;
	vector<P> a(N);//student
	vector<P> c(M);//check point
	rep(i, N)
	{
		cin >> a[i].first >> a[i].second;
	}
	rep(i, M)
	{
		cin >> c[i].first >> c[i].second;
	}
	vector<long> ans;
	rep(i, N)
	{
		long min = LONG_MAX;
		long ord;
		rep(j, M)
		{
			if ((labs(a[i].first - c[j].first) + labs(a[i].second - c[j].second)) < min)
			{
				min = labs(a[i].first - c[j].first) + labs(a[i].second - c[j].second);
				ord = j + 1;
			}
		}
		ans.push_back(ord);
	}
	rep(i, N)
		cout << ans[i] << endl;
	return (0);
}
