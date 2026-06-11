#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

#include <inttypes.h>
using namespace std;

struct edge
{
	int32_t to, cost;
};

int main()
{
	int32_t N, M;
	scanf("%d%d", &N, &M);

	bool edges_exists[100][100];
	for (int32_t i = 0; i < N; i++)
		fill(edges_exists[i], edges_exists[i] + N, false);
	vector<struct edge> edges[100];
	for (int32_t i = 0; i < M; i++) {
		int32_t a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		edges[a].push_back({b, c});
		edges[b].push_back({a, c});
		edges_exists[a][b] = true;
		edges_exists[b][a] = true;
	}

	int32_t d[100], prev[100];

	for (int32_t start = 0; start < N; start++) {
		// dijkstra
		priority_queue<pair<int32_t, int32_t>, vector<pair<int32_t, int32_t>>> pq; // pair<dist, node>
		fill(d, d + N, numeric_limits<int32_t>::max() / 2);
		fill(prev, prev + N, -1);
		d[start] = 0;
		pq.push(make_pair(d[start], start));

		while (!pq.empty()) {
			pair<int32_t, int32_t> p = pq.top(); pq.pop();
			int32_t dist = p.first;
			int32_t node = p.second;
			if (d[node] < dist)
				continue;

			for (size_t i = 0; i < edges[node].size(); i++) {
				struct edge e = edges[node][i];
				if (d[e.to] > d[node] + e.cost) {
					d[e.to] = d[node] + e.cost;
					pq.push(make_pair(d[e.to], e.to));
					prev[e.to] = node;
				}
			}
		}

		// path from end to start
		for (int32_t end = 0; end < N; end++) {
			int32_t node = end;
			while (node != start) {
				edges_exists[node][prev[node]] = false;
				edges_exists[prev[node]][node] = false;
				node = prev[node];
			}
		}
	}

	int32_t res = 0;
	for (int32_t i = 0; i < N; i++)
		for (int32_t j = 0; j < N; j++)
			if(edges_exists[i][j])
				res++;

	printf("%d\n", res / 2);

	return 0;
}