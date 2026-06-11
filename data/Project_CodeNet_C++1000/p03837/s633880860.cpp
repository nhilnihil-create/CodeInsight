#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

#define NMAX (101)
#define INF (100000000)
#define p(a, b) make_pair(a, b)

typedef int COST_TYPE;
typedef pair<COST_TYPE, int> pi;

int N, M;
int a[1000], b[1000], c;

int e[101][101];
bool used[1000];

vector<pi> G[NMAX];
COST_TYPE cost[NMAX];
bool done[NMAX];

void dijkstra(int root)
{
	priority_queue<pi, vector<pi>, greater<pi> > PQ;
	pi current;	/* first: cost, second: index */
	COST_TYPE next_cost;
	int current_index, next_index, size;

	rep(i, NMAX) {
		done[i] = false;
		cost[i] = INF;
	}

	cost[root] = 0;
	PQ.push(make_pair(0, root));

	while (!PQ.empty()) {
		current = PQ.top();
		PQ.pop();

		current_index = current.second;

		if (done[current_index]) continue;
		done[current_index] = true;

		size = (int)G[current_index].size();
		rep(i, size) {
			next_index = G[current_index][i].second;
			next_cost = G[current_index][i].first;

			if ((!done[next_index])
				&& (cost[next_index] > cost[current_index] + (COST_TYPE)next_cost)) {
				cost[next_index] = cost[current_index] + (COST_TYPE)next_cost;
				PQ.push(make_pair(cost[next_index], next_index));
			}
		}
	}
}

void check_used(int root)
{
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int current = q.front(); q.pop();
		int size = G[current].size();

		rep(i, size) {
			pi item = G[current][i];
			int len = item.first;
			int next = item.second;

			if (cost[current] + len == cost[next]) {
				used[e[current][next]] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	int ans = 0;

	cin >> N >> M;
	rep(i, M) {
		cin >> a[i] >> b[i] >> c;
		e[a[i]][b[i]] = i;
		e[b[i]][a[i]] = i;
		G[a[i]].push_back(p(c, b[i]));
		G[b[i]].push_back(p(c, a[i]));
	}

	repc(i, 1, N) {
		dijkstra(i);
		check_used(i);
	}

	rep(i, M) if (!used[i]) ans++;

	cout << ans << endl;

	return 0;
}
