
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template <class _T> static _T tp_abs(const _T& a) {
	//	usage:  tp_abs<type name>(a);
	return ((a < 0) ? (a * -1) : a);
}
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_max(_T a, _T b) {
	return a > b ? a : b;
}
template<class _T> static void get1int(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void get2int(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
static void getstring(char* buff) {
	if (scanf(" %s", buff) < 0) {
		printf("getstr error!\n");
	}
}

static void CodeFest2017qA_C_PalindromicMatrix();

#if 1
int main()
{
	CodeFest2017qA_C_PalindromicMatrix();
	fflush(stdout);
	return 0;
}
#endif

static void CodeFest2017qA_C_PalindromicMatrix()
{
	int H, W;
	get2int(H, W);

	auto tmp = new char[H][101];
	for (int h = 0; h < H; h++) {
		getstring(tmp[h]);
	}

	std::map<char, int> chars;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			chars[tmp[h][w]]++;
		}
	}

	int count[4] = { 0 };
	for (auto it = chars.begin(); it != chars.end(); it++) {
		count[it->second % 4]++;
	}

	const char* ans = "No\n";
	if ((H % 2) && (W % 2)) {
		int elem = (H / 2) + (W / 2);

		if ((count[1] == 1) && (count[2] <= elem) && (count[3] == 0)) {
			ans = "Yes\n";
		}
		else if ((count[1] == 0) && (count[2] <= elem) && (count[3] == 1)) {
			ans = "Yes\n";
		}
	}
	else if ((H % 2) || (W % 2)) {
		int elem = H / 2;
		if (H % 2) elem = W / 2;

		if ((count[2] <= elem) && (count[1] == 0) && (count[3] == 0)) {
			ans = "Yes\n";
		}
	}
	else {
		if ((count[1] == 0) && (count[2] == 0) && (count[3] == 0)) {
			ans = "Yes\n";
		}
	}
	printf(ans);
	delete[] tmp;
}
