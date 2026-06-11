
#include <stdio.h>
#include <string.h>
#include <limits.h>
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

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void ABC073D();

int main()
{
	ABC073D();
	fflush(stdout);
	return 0;
}


static int ABC073Ddfs(std::set<int> town, int cost, int from, std::vector<std::vector<int>>& costs)
{
	int ret = MOD_NUM;

	if (town.size() > 1) {
		town.erase(from);
		for (auto it = town.begin(); it != town.end(); it++) {
			ret = std::min(ret, ABC073Ddfs(town, cost + costs[from][*it], *it, costs));
		}
		town.insert(from);
	}
	else {
		ret = cost;
	}
	return ret;
}

static void ABC073D()
{
	int N, M, R;
	getint(N, M, R);

	std::set<int> town;
	for (int i = 0; i < R; i++) {
		int t;
		getint(t); t--;
		town.insert(t);
	}

	std::vector<std::vector<int>> costs(N, std::vector<int>(N, (int)MOD_NUM));
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		getint(from, to, cost); from--; to--;	//	0-indexed
		costs[from][to] = cost;
		costs[to][from] = cost;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	int minCost = (int)MOD_NUM;
	for (auto it = town.begin(); it != town.end(); it++) {
		minCost = std::min(minCost, ABC073Ddfs(town, 0, *it, costs));
	}
	printf("%d\n", minCost);
}
