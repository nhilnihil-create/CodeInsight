
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
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}
template <class _T> static void tp_swap(_T& right, _T& left) {
	//	usage:  tp_swap<type name>(a, b);
	_T tmp = right;
	right = left;
	left = tmp;
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
	std::string orgs;
	getval(orgs);

	int K;
	getval(K);

	int len = orgs.length();
	for (int i = 0; i < len; i++) {
		int code = orgs[i] - 'a';
		if (!code) continue;
		int ope = 26 - code;

		if (K >= ope) {
			K -= ope;
			orgs[i] = 'a';
		}
	}

	if (K) {
		orgs[len - 1] += (K % 26);
		if (orgs[len - 1] > 'z') {
			orgs[len - 1] -= 'a';
		}
	}
	std::cout << orgs << std::endl;
}
