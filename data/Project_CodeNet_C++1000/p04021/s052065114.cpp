
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
	int N;
	getval(N);

	if (N == 1) {
		printf("0\n");
		return;
	}

	LLONG ai;
	std::map<LLONG, int> index;
	std::vector<LLONG> odd(N / 2), even(N / 2 + N % 2);
	for (int i = 0; i < N; i++) {
		getval(ai);
		if (i % 2) {
			odd[i / 2] = ai;
		}
		else {
			even[i / 2] = ai;
		}
		index[ai] = 1;
	}

	int idx = 0;
	for (auto it = index.begin(); it != index.end(); it++) {
		it->second = idx;
		idx++;
	}

	int ans = 0;
	for (auto it = even.begin(); it != even.end(); it++) {
		if (index[*it] % 2) {
			ans++;
		}
	}

	printf("%d\n", ans);
}
