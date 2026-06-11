
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

	int rate;
	int color = 0;
	std::vector<int> members(9, 0);
	for (int i = 0; i < N; i++) {
		getval(rate);
		int upper = 399;
		bool freeCol = true;
		for (int col = 0; col < 8; col++) {
			if (rate <= upper) {
				members[col]++;
				freeCol = false;
				break;
			}
			upper += 400;
		}
		if (freeCol) {
			members[8]++;
		}
	}

	int min = 0, max = 0;
	for (int i = 0; i < 8; i++) {
		if (members[i]) {
			min++;
		}
	}
	max = min;
	if (members[8]) {
		max = min + members[8];
		if (min == 0) min++;
	}
	printf("%d %d\n", min, max);
}
