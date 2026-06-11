#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)

const ll MOD = 1000000007;

using namespace std;

int num(int n)
{
	int ng = n + 1;
	int ok = 1;
	while (abs(ng - ok) > 1)
	{
		ll m = (ll)((ng + ok) / 2);
		if (n > m*(m - 1) / 2)
		{
			ok = m;
		}
		else
		{
			ng = m;
		}
	}
	return ok;
}

int main()
{
	int N;
	cin >> N;
	while (N != 0)
	{
		int n = num(N);
		cout << n << endl;
		N -= n;
	}
	return 0;
}