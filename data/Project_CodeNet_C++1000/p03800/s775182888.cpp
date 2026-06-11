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

static void ARC069D_Menagerie();

#if 1
int main()
{
	ARC069D_Menagerie();
	fflush(stdout);
	return 0;
}
#endif

static void ARC069D_Menagerie()
{
	int N;
	get1int(N);

	auto seq = new char[N + 1];
	getstring(seq);
	auto ans = new char[N + 1];
	ans[N] = 0;

	const char* first = "SSWW";
	const char* second = "SWSW";
	bool success = true;
	for (int i = 0; i < 4; i++) {
		ans[0] = first[i];
		ans[1] = second[i];

		for (int j = 1; j < (N - 1); j++) {
			int next = j + 1;
			int bfr = j - 1;

			if (ans[j] == 'S') {
				if (seq[j] == 'o') {
					ans[next] = ans[bfr];
				}
				else {
					if (ans[bfr] == 'S') ans[next] = 'W';
					else ans[next] = 'S';
				}
			}
			else {
				if (seq[j] == 'o') {
					if (ans[bfr] == 'S') ans[next] = 'W';
					else ans[next] = 'S';
				}
				else {
					ans[next] = ans[bfr];
				}
			}
		}

		success = true;
		for (int j = 0; j < N; j++) {
			int next = j + 1;
			int bfr = j - 1;
			if (next >= N) next = 0;
			if (bfr < 0) bfr = N - 1;

			if (ans[j] == 'S') {
				if (seq[j] == 'o') {
					if (ans[bfr] != ans[next]) {
						success = false;
						break;
					}
				}
				else {
					if (ans[bfr] == ans[next]) {
						success = false;
						break;
					}
				}
			}
			else {
				if (seq[j] == 'o') {
					if (ans[bfr] == ans[next]) {
						success = false;
						break;
					}
				}
				else {
					if (ans[bfr] != ans[next]) {
						success = false;
						break;
					}
				}
			}
		}
		if (success) break;
	}
	if (success) printf("%s\n", ans);
	else printf("-1\n");

	delete[] seq;
	delete[] ans;
}
