
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
	std::vector<int> ai(N), bi(N);
	for (int i = 0; i < N; i++) {
		get(ai[i]);
	}
	if (N == 1) {
		printf("%d\n", ai[0]);
		return;
	}
	int end1 = (N + 1) / 2;
	int first = N - 1, first2 = N % 2;

	for (int i = 0; i < end1; i++) {
		bi[i] = ai[first - (i * 2)];
	}
	for (int i = end1; i < N; i++) {
		bi[i] = ai[first2 + (i - end1) * 2];
	}
	std::string ans;
	for (int i = 0; i < N; i++) {
		if (ans.length()) ans += ' ';
		char tmp[16] = { 0 };
		sprintf(tmp, "%d", bi[i]);
		ans += tmp;
	}
	printf("%s\n", ans.c_str());
}
