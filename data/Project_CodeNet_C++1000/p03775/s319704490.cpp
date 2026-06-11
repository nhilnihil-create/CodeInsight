
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
static const LLONG MOD_NUM = 1000000007;//998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template<class _T> static void getint(_T& a) {
	if (sizeof(_T) > sizeof(int)) {
		scanf("%lld", &a);
	}
	else {
		scanf("%d", &a);
	}
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
	LLONG N;
	get(N);

	int ans = MOD_NUM;
	LLONG limit = (LLONG)sqrt(N) + 1;
	for (int i = 1; i <= limit; i++) {
		if (N % i == 0) {
			LLONG A = N / i;

			int da = 0;
			while (A) {
				da++;
				A /= 10;
			}
			LLONG B = i;
			int db = 0;
			while (B) {
				db++;
				B /= 10;
			}
			ans = std::min(std::max(da, db), ans);
		}
	}
	printf("%d\n", ans);
}
