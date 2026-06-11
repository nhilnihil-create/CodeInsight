#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	long n, m; cin >> n >> m;
	long sum = 0;
	if (n*2 <= m)
	{
		m -= (n * 2);
		sum += n;
		sum += m/4;
	}
	else
	{
		if(n >= (m / 2))
		{
			sum += (m/2);
		}
		else
		{
			sum += n;
			m -= (2*n);
			sum += m/4;
		}
	}
	cout << sum << endl;
	return 0;
}