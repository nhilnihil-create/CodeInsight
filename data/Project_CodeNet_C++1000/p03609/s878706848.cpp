#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	long x,t; cin >> x >> t;

	if (x >= t)
		cout << x - t << endl;
	else
		cout << 0 << endl;
	return 0;
}