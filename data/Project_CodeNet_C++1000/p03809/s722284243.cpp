
#include <cstdio>
#include <cstdlib>

using namespace std;
const int Max_N(100050);
typedef long long int LL;

template<typename Type>
void Get_Val(Type &Ret)
{
	Ret = 0;
	char ch;
	while (ch = getchar(), ch > '9' || ch < '0')
		;
	do
	{
		(Ret *= 10) += ch - '0';
	}
	while (ch = getchar(), ch >= '0' && ch <= '9');
}

int N, root, Head[Max_N], Total, To[Max_N << 1], Next[Max_N << 1], Deg[Max_N];
LL A[Max_N];

inline void Add_Edge(const int &s, const int &t)
{
	++Total, To[Total] = t, Next[Total] = Head[s], Head[s] = Total;
}

void init()
{
	Get_Val(N);
	for (int i = 1;i <= N;++i)
		Get_Val(A[i]);
	for (int i = 1, u, v;i != N;++i)
		Get_Val(u), Get_Val(v), Add_Edge(u, v), Add_Edge(v, u), ++Deg[u], ++Deg[v];
	for (int i = 1;i <= N;++i)
		if (Deg[i] > 1)
			root = i;
}

inline void GG()
{
	puts("NO"), exit(0);
}

/*
首先选择一个不是叶子的点root作为根 
考虑从下往上处理。那么考虑一个点u和它儿子时，它的每个儿子都会伸出一些的路径，期望在上面得到匹配
设u的儿子总共伸出了Sum条路径，假设当前点的权值是v。设有x(0 <= 2x <= Sum)对路径是在u处得到匹配，有(Sum - 2x) + x = v，同时u会向上伸出Sum - 2x条路径
x是固定的可以直接解出。现在问题转化成，从每个儿子处选一些向上走的路径、总共选Sum - 2x条，使得剩下的路径可以两两匹配
这是一个经典问题。具体而言是：有n个集合，每个集合中有若干个点，判断能否让这些点两两匹配，使得匹配的点对不在同一个集合中
可以证明，当2 * Max <= Sum且Sum是偶数时能存在这样的匹配。必要性显然，充分性可以考虑去掉一个最大值后构造
贪心判定能否使得Max <= floor(Sum / 2)即可，这里Sum = 2x 
*/

void dfs(const int &u, const int &fa)
{
	if (Deg[u] == 1)
		return;
	LL Sum(0LL), X;
	for(int i = Head[u], v;i;i = Next[i])
		if ((v = To[i]) != fa)
			dfs(v, u), Sum += A[v];
	X = Sum - A[u];
	if (!(0LL <= 2LL * X && 2LL * X <= Sum))
		GG();
	LL need(0LL);
	for (int i = Head[u], v;i;i = Next[i])
		if ((v = To[i]) != fa)
			if (A[v] > X)
				need += A[v] - X;
	if (need > (A[u] = Sum - 2LL * X))
		GG();
}

void work()
{
	dfs(root, -1);
	puts(A[root] ? "NO" : "YES");
}

int main()
{
	init();
	if (root)
		work();
	else
		puts(A[1] == A[2] ? "YES" : "NO");
	return 0;
}