
// MAGRANT - GNC19 - TEMPLATE 3.2
// DATE - PROBLEM
// PRACTISING TIME TAGS:
// ALGORITHM: ##MIN, STARTED AT:
// CODING: ##MIN, STARTED AT:
// SUMMARY: [MISTAKES / REQUISITES]

// FOR COMPATIBILITY:
#define _CRT_SECURE_NO_WARNINGS

// UNIVERSAL DEFINITIONS:
#define N (1<<17)
#define MODULO (1000000007)
#define HA1 (2420609)
#define HA2 (19260817)

// FREQUENT HEADER FILES:
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <complex>
using namespace std;

// TEMPLATE BEGINS HERE.
//#define MAGRANT_ALLOWS_CTMP
// IMPORTANT: DO NOT OPEN UNLESS AS CONTESTANT.
// CAUTION: BEWARE OF CONFLICT.
#ifdef MAGRANT_ALLOWS_CTMP
namespace CTMP
{
	// ELEMENTARY MATHEMATICAL COMPUTATIONS:
	long long fact[N], inv[N];
	long long KissMe(long long xx, long long yy)
	{
		if (yy == 0LL)
		{
			return 1LL;
		}
		long long Res = KissMe((xx*xx) % (long long)MODULO, yy >> 1);
		if (yy % 2LL == 1LL)
		{
			Res *= xx;
			Res %= (long long)MODULO;
		}
		return Res;
	}
	inline void InitFactInv()
	{
		fact[0] = 1LL;
		for (int i = 1;i < N - 4;i++)
		{
			fact[i] = fact[i - 1] * (long long)i;
			fact[i] %= (long long)MODULO;
		}
		inv[N - 5] = KissMe(fact[N - 5], (long long)(MODULO - 2));
		for (int i = N - 6;i >= 0;i--)
		{
			inv[i] = inv[i + 1] * (long long)(i + 1);
			inv[i] %= (long long)MODULO;
		}
	}
	inline long long Choose(int xx, int yy)
	{
		if (xx < yy)
		{
			return 0LL;
		}
		else if (xx == yy)
		{
			return 1LL;
		}
		long long Res = fact[xx];
		Res *= inv[yy];
		Res %= (long long)MODULO;
		Res *= inv[xx - yy];
		Res %= (long long)MODULO;
		return Res;
	}
	inline long long GridWays(int fx, int fy, int sx = 0, int sy = 0)
	{
		fx -= sx, fy -= sy;
		if (fx < 0 || fy < 0)
		{
			return 0LL;
		}
		long long Res = fact[fx + fy];
		Res *= inv[fx];
		Res %= (long long)MODULO;
		Res *= inv[fy];
		Res %= (long long)MODULO;
		return Res;
	}
}
#endif
// TEMPLATE FINISHES HERE.

int n, m;
char s[N];
long long dp1[N], dp2[N];

int main()
{
	// IMPORTANT: DO NOT OPEN UNLESS AS CONTESTANT.
	// CAUTION: BEWARE OF CONFLICT.
	//using namespace CTMP;

	// REAFFIRM THE FOLLOWING BEFORE CODING.
	// 1. THE ALGORITHM IS CORRECT.
	// 2. THE COMPLEXITY IS PROPER.
	// 3. THE ALGORITHM CANNOT BE SIMPLER.
	// 4. CODING DETAILS WERE CONSIDERED.

	scanf("%d", &n);
	scanf("%s", s);
	m = strlen(s);
	dp2[0] = 1LL;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m + n;j++)
		{
			if (j)
			{
				dp1[j] = dp2[j - 1] + (dp2[j + 1] << 1);
				while (dp1[j] >= (long long)MODULO)
				{
					dp1[j] -= (long long)MODULO;
				}
			}
			else
			{
				dp1[j] = dp2[j] + (dp2[j + 1] << 1);
				while (dp1[j] >= (long long)MODULO)
				{
					dp1[j] -= (long long)MODULO;
				}
			}
		}
		for (int j = 0;j <= m + n;j++)
		{
			dp2[j] = dp1[j];
		}
	}
	printf("%lld\n", dp1[m]);

	// REAFFIRM THE FOLLOWING BEFORE SUBMITTING.
	// 1. THE ARRAYS ARE IN PROPER SIZE.
	// 2. THE CORNER CASES WILL NOT LEAD TO VIOLATION.
	// 3. NO TYPO LIKE N->M EXISTS.
	// 4. THE INPUT/OUTPUT IS IN THE SPECIFIED FORMAT.
	// 5. ALL CATEGORIES DO NOT INTERSECT.
	//system("pause");
	return 0;
}
