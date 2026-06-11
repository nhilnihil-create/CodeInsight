
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	int N;
	getval(N);

	std::vector<LLONG> ai(3 * N);
	for (int i = 0; i < 3 * N; i++) {
		getval(ai[i]);
	}
	std::sort(ai.begin(), ai.end(), std::greater<LLONG>());

	LLONG ans = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (i % 2) ans += ai[i];
	}
	printf("%lld\n", ans);
}
