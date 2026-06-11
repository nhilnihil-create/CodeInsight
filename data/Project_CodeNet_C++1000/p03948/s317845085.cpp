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

int A[100005];
int C[100005];
int main()
{
	int N, T;
	cin >> N >> T;
	REP(i, N)
	{
		cin >> A[i];
	}
	int max = A[N - 1];
	IREP(i, N - 1)
	{
		max = std::max(A[i], max);
		C[i] = max - A[i];
	}

	sort(C, C + N, [](int a, int b) {return a > b; });
	int ans = 0;
	REP(i, N)
	{
		if (C[0] != C[i])break;
		ans++;
	}

	cout << ans << endl;
	return 0;
}