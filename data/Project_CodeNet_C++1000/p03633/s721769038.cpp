
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

template <class _T> static _T tp_gcd(_T first, _T second)
{
	_T num1 = first, num2 = second;
	_T remainder = 0, common = 0;

	if (!num1) return num2;
	if (!num2) return num1;

	while (!common) {
		remainder = num1 % num2;

		if (remainder == 0) {
			common = num2;
		}
		else {
			num1 = num2;
			num2 = remainder;
		}
	}
	return(common);
}
template <class _T> static _T tp_lcm(_T first, _T second) {
	_T gcd = tp_gcd<_T>(first, second);
	if (first > second) {
		first /= gcd;
	}
	else {
		second /= gcd;
	}
	return first * second;
}

static void exec()
{
	int N;
	get(N);

	std::vector<LLONG> ti(N);
	for (int i = 0; i < N; i++) {
		get(ti[i]);
	}

	LLONG lcm = 1;
	for (int i = 0; i < N; i++) {
		lcm = tp_lcm<LLONG>(lcm, ti[i]);
	}
	printf("%lld\n", lcm);
}
