
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
	LLONG N, A, B, C, D;
	getint(N, A, B);
	getint(C, D);
	
	LLONG sumYi = B - A;
	for (LLONG m = 1; m < N; m++) {
		LLONG left = C * (N - 1 - m) - D * m;
		LLONG right = D * (N - 1 - m) - C * m;

		if ((left <= sumYi) && (sumYi <= right)) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
