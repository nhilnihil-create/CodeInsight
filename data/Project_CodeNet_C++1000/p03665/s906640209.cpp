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
static const LLONG MOD_NUM = 998244353;//1000000007;

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
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= (_T)base;
	}
	return ans;
}

static void exec()
{
	int N, P;
	getval(N, P);

	int a, odd = 0;
	for (int i = 0; i < N; i++) {
		getval(a);
		if (a % 2) odd++;
	}

	LLONG ans = 0;
	if (odd == 0 && P) {
		printf("%lld\n", ans);
		return;
	}

	if (odd) {
		ans = tp_pow<LLONG>(2, N - 1);
	}
	else {
		ans = tp_pow<LLONG>(2, N);
	}
	printf("%lld\n", ans);
}
