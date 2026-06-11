
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
	int N;
	get(N);
	std::string s, t;
	get(s, t);

	int match = 0;
	for (int st = 0; st < N; st++) {
		bool ng = false;
		for (int i = 0; i < N - st; i++) {
			if (s[st + i] != t[i]) ng = true;
		}
		if (!ng) {
			match = std::max(match, N - st);
		}
	}
	printf("%d\n", N * 2 - match);
}
