#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n) cin >> a[i];

	int ans;
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i = -100; i <= 100; i++)
	{
		ans = 0;
		for (int j = 0; j < n; j++)
		{
			ans += abs(i-a[j]) * abs(i-a[j]);
		}
		pq.push(ans);
	}
	cout << pq.top() << endl;
	return 0;
}
