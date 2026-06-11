
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

static void ABC070D();

int main()
{
	ABC070D();
	fflush(stdout);
	return 0;
}

class edge {
public:
	int to = 0;
	LLONG cost = 0;
};

static void dijkstra(int st, std::vector<LLONG>& costs, std::vector<std::vector<edge>>& graph)
{
	std::priority_queue<
		std::pair<LLONG, LLONG>,
		std::vector<std::pair<LLONG, LLONG>>,
		std::greater<std::pair<LLONG, LLONG>>> que;

	costs[st] = 0;
	que.push(std::pair<LLONG, LLONG>(0, st));

	while (!que.empty()) {
		std::pair<LLONG, LLONG> p = que.top(); que.pop();
		int v = (int)p.second;

		if ((costs[v] != -1LL) && (costs[v] < p.first)) continue;

		int eCount = graph[v].size();
		for (int e = 0; e < eCount; e++) {
			edge ed = graph[v][e];
			if ((costs[ed.to] == -1LL) ||
				(costs[ed.to] > costs[v] + ed.cost)) {
				costs[ed.to] = costs[v] + ed.cost;
				que.push(std::pair<LLONG, LLONG>(costs[ed.to], ed.to));
			}
		}
	}
}

static void ABC070D()
{
	int N;
	getint(N);

	std::vector<std::vector<edge>> graph(N);
	for (int i = 0; i < N - 1; i++) {
		int from, to, cost;
		getint(from, to, cost); from--; to--;

		edge e;
		e.to = to;
		e.cost = cost;
		graph[from].push_back(e);
		
		e.to = from;
		graph[to].push_back(e);
	}

	int Q, K;
	getint(Q, K); K--;

	std::vector<LLONG> costs(N, -1LL);
	dijkstra(K, costs, graph);

	std::vector<LLONG> ans(Q, 0);
	for (int i = 0; i < Q; i++) {
		int from, to;
		getint(from, to); from--; to--;
		ans[i] = costs[from] + costs[to];
	}
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", ans[i]);
	}
}
