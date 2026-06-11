#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;
const int MaxM = 200000;

int n, m;

struct halfEdge
{
	int v;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

int num[3];	// num[0]: isolated vertices; num[1]: non-bipartite components; num[2]: bipartite components

int col[MaxN + 1];

bool valid;
int total;

void dfs(const int &u, const int &now)
{
	col[u] = now, ++total;

	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		if (!col[e->v])
			dfs(e->v, now ^ 1);
		else if (col[e->v] != now ^ 1)
			valid = false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u = getint(), v = getint();
		addEdge(u, v);
		addEdge(v, u);
	}

	for (int u = 1; u <= n; ++u)
		if (!col[u])
		{
			valid = true, total = 0;
			dfs(u, 2);

			num[0] += total == 1;
			num[1] += !valid;
			num[2] += valid && total > 1;
		}

	s64 a = num[0], b = num[1], c = num[2];
	s64 p = n * a * 2ll - a * a;
	s64 q = b * b + 2ll * b * c + 2ll * c * c;
	cout << p + q << endl;

	return 0;
}