//by OIerC
//Forca Barcelona!
#include<cstdio>
#include<vector>
using namespace std;

inline int read()
{
 	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2e5 + 5;
vector<int> G[N];
int SG[N];

void dfs(int u, int fa)
{
	SG[u] = 0;
	for (int v : G[u]) if (v != fa)
		dfs(v, u), SG[u] ^= (SG[v] + 1);
}

int main()
{
	int n = read();
	for (int i = 1; i < n; ++i)
	{
		int u = read();
		int v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	
	puts(SG[1] ? "Alice" : "Bob");
	
	return 0;
}
