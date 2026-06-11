#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= (_T)base;
	}
	return ans;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	int N, P;
	get(N, P);

	std::vector<int> ai(N);
	int odd = 0, even = 0;
	for (int i = 0; i < N; i++) {
		get(ai[i]);
		if (ai[i] % 2) odd++;
		else even++;
	}

	LLONG ans = 0;
	if (N == 1) {
		if (P) {
			if (odd) ans = 1;
		}
		else {
			if (even) ans = 2;
			else ans = 1;
		}
	}
	else if (P == 1 && odd == 0) {
		ans = 0;
	}
	else if (P == 0 && odd == 0) {
		ans = tp_pow<LLONG>(2, N);
	}
	else {
		ans = tp_pow<LLONG>(2, N - 1);
	}
	printf("%lld\n", ans);
}
