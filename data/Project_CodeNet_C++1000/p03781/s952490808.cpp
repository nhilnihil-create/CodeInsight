#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

int main()
{
	ll X;
	cin >> X;
	int i = 1;
	ll sum = 0;
	while (true)
	{
		sum += i;
		if (sum - X <= i && sum - X >= 0)break;
		i++;
	}
	cout << i << endl;
	return 0;
}