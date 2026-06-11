#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int Digit(LLONG n)
{
	int digit = 0;
	do {
		n /= 10;
		++digit;
	} while (n > 0);
	return digit;
}

int main()
{
	LLONG N; cin >> N;
	// O(sqrt(N) * digit(N)) ~ O(10^6)
	int ans = 100;
	for (LLONG a = 1; a * a <= N; ++a)
	{
		if (N % a == 0)
		{
			int tmp = max(Digit(a), Digit(N / a));
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
}