#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
struct ss{
	int next, to;
};ss data[N];
int n, k, p, ans;
int head[N], To[N];
inline void add(int a, int b)
{
	data[++p].next = head[a];
	data[p].to = b;
	head[a] = p;
}
int dfs(int a, int deep)
{
	int d = deep;
	for(int i = head[a];i;i = data[i].next)
	{
		int v = data[i].to;
		d = max(d, dfs(v, deep + 1));
	}
	if(d - deep == k - 1 && To[a] != 1)
	{
		ans ++;
		return 0;
	}
	return d;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n; ++i) scanf("%d", &To[i]);
	if(To[1] != 1) ans++, To[1] = 1;
	for(int i = 2;i <= n; ++i) add(To[i], i);
	dfs(1, 0);
	//if(ans)
	printf("%d\n", ans);
	return 0;
}