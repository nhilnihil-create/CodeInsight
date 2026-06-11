
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
	int N, M;
	get(N);

	std::vector<LLONG> ti(N);
	LLONG sum = 0;
	for (int i = 0; i < N; i++) {
		get(ti[i]);
		sum += ti[i];
	}

	get(M);
	std::vector<std::pair<LLONG, LLONG>> pi(M);
	for (int i = 0; i < M; i++) {
		get(pi[i].first, pi[i].second);
	}

	for (int i = 0; i < M; i++) {
		printf("%lld\n", sum - ti[pi[i].first - 1] + pi[i].second);
	}
}
