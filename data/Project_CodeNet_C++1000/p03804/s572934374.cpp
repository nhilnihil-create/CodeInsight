
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
static const LLONG MOD_NUM = 1000000007;//998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template<class _T> static void getint(_T& a) {
	if (sizeof(_T) > sizeof(int)) {
		scanf("%lld", &a);
	}
	else {
		scanf("%d", &a);
	}
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
	int N, M;
	get(N, M);

	std::vector<std::string> pica(N), picb(M);
	for (int i = 0; i < N; i++) {
		get(pica[i]);
	}
	for (int i = 0; i < M; i++) {
		get(picb[i]);
	}

	for (int ni = 0; ni < N; ni++) {
		for (int nj = 0; nj < N; nj++) {
			bool match = true;
			for (int mi = 0; mi < M; mi++) {
				for (int mj = 0; mj < M; mj++) {
					if (((ni + M) > N) || ((nj + M) > N)) {
						match = false;
						break;
					}
					else if (pica[ni + mi][nj + mj] != picb[mi][mj]) {
						match = false;
						break;
					}
				}
				if (!match) break;
			}
			if (match) {
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}
