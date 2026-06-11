#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

long gcd(long a, long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

/* lcm(最小公倍数) */
long lcm(long a, long b)
{
	return ( (a * b) / gcd(a, b) );
}

int  main()
{
	int a,b,c;
	cin >> a >> b >> c;
	for (int i = 1; i <= b ; i++)
	{
		if ((i*a) % b == c)
		{
			cout << "YES"; return 0;
		}
	}
	cout << "NO" << endl;
	return (0);
}
