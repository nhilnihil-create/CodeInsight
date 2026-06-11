
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

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	std::string S;
	get(S);

	int len = S.length();
	int second = 0;
	for (int i = 2; i < len; i += 2) {
		second = len / 2 - i / 2;
		bool isOk = true;
		for (int first = 0; first < second; first++) {
			if (S[first] != S[second + first]) {
				isOk = false;
				break;
			}
		}
		if (isOk) {
			break;
		}
	}
	printf("%d\n", second * 2);
}
