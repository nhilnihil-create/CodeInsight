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
ll a[200005] = {};
ll s[200005] = {};
int main()
{
	int N;
	cin >> N;
	REP(i, N)
	{
		cin >> a[i];
		s[i] += a[i];
		if (i > 0) s[i] += s[i - 1];
	}

	ll min = 1000000001 * 2;
	REP(i, N - 1)
	{
		ll z = abs(s[i] - (s[N - 1] - s[i]));
		if (z < min)min = z;
	}

	cout << min << endl;
	return 0;
}