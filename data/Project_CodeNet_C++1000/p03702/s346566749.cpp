#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <queue>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

ll ceil(ll a, ll b)
{
	return (a + b - 1) / b;
}

ll H[100005];
ll N, A, B;

bool check(ll n)
{
	ll sum = n;
	REP(i, N)
	{
		sum -= ceil(H[i] - n*B, A - B);
		if (sum < 0)break;
	}
	return sum >= 0;
}

int main()
{
	cin >> N >> A >> B;
	ll max = 0;
	REP(i, N)
	{
		cin >> H[i];
		max += ceil(H[i], A);
	}
	sort(H, H + N, [](ll a, ll b) {return a > b; });
	ll ng = 0, ok = max;
	while (abs(ok - ng) > 1)
	{
		ll mid = (ok + ng) / 2;
		if (check(mid))
		{
			ok = mid;
		}
		else
		{
			ng = mid;
		}
	}
	cout << ok << endl;
	return 0;
}