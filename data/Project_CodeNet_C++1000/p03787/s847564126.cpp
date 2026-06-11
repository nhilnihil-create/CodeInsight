/*************************************************************************
> File Name: test.cpp
> Author: Akira
> Mail: qaq.febr2.qaq@gmail.com
************************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;
 
#define MaxN 100001
#define MaxM MaxN*4
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9 + 7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int N, M;
struct Edge
{
	int u, v, next;
}edge[MaxM];
int cont;
int head[MaxN];
vector<int> V[MaxN];
void add(int u, int v)
{
	edge[cont].u = u;
	edge[cont].v = v;
	edge[cont].next = head[u];
	head[u] = cont++;
}
void Add(int u, int v) { add(u, v); add(v, u); }
int low[MaxN];
int dfn[MaxN];
int Stack[MaxN], top;
int belong[MaxN];
int vis[MaxN];
int Index, cnt;
void Tarjan(int u)
{
	low[u] = dfn[u] = Index;
	Index++;
	Stack[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (dfn[v] == -1)
		{
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u])
	{
		for (int v=-1; v != u; top--)
		{
			v = Stack[top];
			vis[v] = false;
			belong[v] = cnt;
			V[cnt].push_back(v);
		}
		cnt++;
	}
}
int col[MaxN];
bool BFS(int x)
{
	col[x] = 1;
	queue<int> Q;
	Q.push(x);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (col[v] == col[u]) return false;
			else
			{
				if (col[v] == -1)
				{
					col[v] = col[u] ^ 1;
					Q.push(v);
				}
			}
		}
	}
	return true;
}
bool judge(int x)
{
	MST(col, -1);
	for (int i = 0; i<V[x].size(); i++)
	{
		int node = V[x][i];
		if (col[node] == -1 && !BFS(node)) return false;
	}
	return true;
}
void init()
{
	cont = 0;
	MST(head, -1);
	MST(dfn, -1);
	CLR(low);
	CLR(vis);
	Index = cnt = 1;
	top = 0;
	for (int i = 1; i <= N; i++) V[i].clear();
}
int main()
{
	//std::ios::sync_with_stdio(false);
	while (~scanf("%d%d", &N, &M))
	{
		init();
		while (M--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			Add(u, v);
		}
		for (int i = 1; i <= N; i++)
			if (dfn[i] == -1) Tarjan(i);
		//cout << cnt << endl;
		LL I = 0, Q = 0, P = 0;
		for (int i = 1; i<cnt; i++)
		{
			if (V[i].size() == 1) I++;
			else
			{
				if (judge(i)) Q++;
				else P++;
			}
		}
		//cout << I << " " << Q << " " << P << endl;
		LL ans = 2 * I*N - I*I + P*P + 2 * P*Q + 2 * Q*Q;
		printf("%lld\n", ans);
	}
	//system("pause");
}