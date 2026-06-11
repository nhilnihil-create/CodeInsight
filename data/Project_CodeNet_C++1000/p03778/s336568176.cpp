#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int w,a,b; cin >> w >> a >> b;

	if (a < b)
	{
		if (b - (a+w) > 0)
			cout << b - (a+w)<< endl;
		else
			cout << 0;
	}
	else
	{
		if (a - (b+w) > 0)
			cout << a - (b+w) << endl;
		else
			cout << 0;
	}
	return (0);
}
