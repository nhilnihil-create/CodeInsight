#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 300010, M = 2 * N, mod = 1e9 + 7;

int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
LL dist[N];
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void Dijkstra(int root)
{
	memset(dist, 0x3f, sizeof dist);
	dist[root] = 0;
	heap.push({dist[root], root});
	
	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		
		int v = t.S, d = t.F;
		st[v] = true;
		
		for (int i = h[v]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[v] + w[i])
			{
				dist[j] = dist[v] + w[i];
				heap.push({dist[j], j});
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	
	scanf("%d%d", &m, &k);
	Dijkstra(k);
	
	for (int i = 0; i < m; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", (LL)dist[a] + (LL)dist[b]);
	}
    return 0;
}
