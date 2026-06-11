
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
	
	int from, to;
	std::vector<int> balls(N, 1);
	std::set<int> red;

	red.insert(0);
	for (int i = 0; i < M; i++) {
		get(from, to); from--; to--;
		
		balls[from]--;
		balls[to]++;
		if (red.find(from) != red.end()) {
			red.insert(to);
			if (balls[from] == 0) {
				red.erase(from);
			}
		}
	}

	printf("%d\n", (int)red.size());
}
