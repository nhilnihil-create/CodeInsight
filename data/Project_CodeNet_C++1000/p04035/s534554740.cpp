
#include <stdio.h>
#include <string.h>
#include <limits.h>
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

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
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
	int N, L;
	getint(N, L);

	int core = -1;
	LLONG bfr = 0;
	std::vector<LLONG> ai(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
		if (bfr + ai[i] >= L) {
			core = i + 1;
		}
		bfr = ai[i];
	}
	if (core < 0) {
		printf("Impossible\n");
		return;
	}
	printf("Possible\n");

	for (int i = N - 1; i >= core; i--) {
		printf("%d\n", i);
	}
	for (int i = 1; i < core; i++) {
		printf("%d\n", i);
	}
}
