
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
static const LLONG MOD_NUM = 998244353; //1000000007;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	int N;
	get(N);

	std::vector<int> ai(N);
	for (int i = 0; i < N; i++) {
		get(ai[i]);
	}

	int surp = 0;
	LLONG ans = 0;
	for (int i = 0; i < N; i++) {
		ans += ai[i] / 2;
		if (ai[i] % 2 && surp) {
			ans++;
			surp = 0;
		}
		else if (ai[i] && surp && ai[i] % 2 == 0) {
			surp = 1;
		}
		else {
			surp = ai[i] % 2;
		}
	}

	printf("%lld\n", ans);
}
