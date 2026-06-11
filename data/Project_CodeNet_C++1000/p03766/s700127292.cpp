#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 1e6 + 10;
const int MOD = 1e9 + 7;

int dp[MR];

int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = n;
	dp[2] = n*(LL)n % MOD;

	int sum = n*(LL)(n - 1) % MOD, q = 2 * n - 2;
	queue<int> Q;
	REP(i, 2*n - 2)
		Q.push(1);

	FORQ(i, 3, n)
	{
		dp[i] = (sum + dp[i - 1]) % MOD;

		sum -= q;
		sum += MOD;
		sum %= MOD;
		
		q += dp[i - 2];
		q %= MOD;
		
		Q.push(dp[i - 2]);
		
		q -= Q.front();
		q += MOD;
		q %= MOD;

		sum += q;
		sum %= MOD;

		Q.pop();
	}

	printf("%d\n", dp[n]);

	return 0;
}