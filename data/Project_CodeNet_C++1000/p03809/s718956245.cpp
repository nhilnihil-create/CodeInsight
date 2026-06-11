#include <algorithm>
#include <cstdio>
#include <vector>

#define REDIRECT(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define CLOSEALL() fclose(stdin), fclose(stdout)
using namespace std;

typedef long long i64;
const int MAXN = 1e5 + 10;

int N, A[MAXN];
int edgeLabel[MAXN];
vector<int> Adj[MAXN];

class no_solution: public std::exception
{
public:
	no_solution()
	{
	}

	const char * what() const noexcept
	{
		return "no solution under such constrains";
	}
};

inline void addEdge(int u, int v)
{
	Adj[u].push_back(v);
	Adj[v].push_back(u);
}

int DFS(int cur, int pre)
{
	if(Adj[cur].size() == 1)
		return A[cur];

	i64 sum = 0;
	int tmp, mx = 0;

	for(int to : Adj[cur])
	{
		if(to == pre)
			continue;
		tmp = DFS(to, cur);

		mx = max(mx, tmp);
		sum += tmp;
	}

	if(pre == 0)
	{
		if(sum % 2)
			throw no_solution();
		if(mx > sum / 2)
			throw no_solution();
		if(A[cur] != sum / 2)
			throw no_solution();
		return 0;
	}

	i64 delta = sum - A[cur];
	if(A[cur] < delta || sum < A[cur])
		throw no_solution();
	if(sum - mx < delta)
		throw no_solution();
	return (A[cur] - delta);
}

int main()
{

	int u, v;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i < N; i++)
		scanf("%d%d", &u, &v), addEdge(u, v);

	if (N == 2)
	{
		puts(A[1] == A[2] ? "YES" : "NO");
		return 0;
	}
	try
	{
		for (int i = 1; i <= N; i++)
			if (Adj[i].size() > 1)
			{
				DFS(i, 0);
				break;
			}
		puts("YES");
	} catch (std::exception & x)
	{
		puts("NO");
	}

	return 0;
}
