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
	int N;
	getint(N);
	
	std::vector<LLONG> ai(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}

	LLONG ans[2] = { 0 };
	for (int k = 0; k < 2; k++) {
		LLONG sum = ai[0];
		if (k == 0) {
			if (sum <= 0) {
				ans[k] += (tp_abs(sum) + 1);
				sum = 1;
			}
		}
		else {
			if (sum >= 0) {
				ans[k] += (tp_abs(sum) + 1);
				sum = -1;
			}
		}

		for (int i = 1; i < N; i++) {
			int bfrSign = (sum > 0) ? 1 : -1;

			sum += ai[i];
			if ((bfrSign > 0) && (sum >= 0)) {
				ans[k] += (tp_abs(sum) + 1);
				sum = -1;
			}
			else if ((bfrSign < 0) && (sum <= 0)) {
				ans[k] += (tp_abs(sum) + 1);
				sum = 1;
			}
		}
	}
	printf("%lld\n", std::min(ans[0], ans[1]));
}
