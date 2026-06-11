/* 
容易发现这么几个性质：
(1)1一定在基环树的环上。否则在环上的点无法到达1
(2)当环的大小n >= 2时，给每个点按照顺序在mod n意义下标号，那么i + K != j + K(mod n)   <=>   i != j(mod n)。所以环的大小 = 1
那么最终一定呈现这样的结构：1往1连一个自环，剩下的点形成以1为根的深度<= K的树
把1的边连向1得到一棵树，剩下的点从下往上做，当一个点中的叶子不满足条件时接向根 
*/

#include <cstdio>
#include <algorithm>

using namespace std;
const int Max_N(100050);

int N, K, Ans, Father[Max_N], Head[Max_N], To[Max_N], Next[Max_N];

int dfs(int u)
{
	int Dep(0);
	for (int i = Head[u], v, dep;i;i = Next[i])
	{
		dep = dfs(v = To[i]) + 1;
		if (dep >= K && u != 1)
			++Ans;
		else
			Dep = max(Dep, dep);
	}
	return Dep;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1;i <= N;++i)
	{
		scanf("%d", Father + i);
		if (i == 1)
		{
			if (Father[i] != 1)
				++Ans;
		}
		else
			To[i] = i, Next[i] = Head[Father[i]], Head[Father[i]] = i;
	}
	dfs(1);
	printf("%d", Ans);
	return 0;
}