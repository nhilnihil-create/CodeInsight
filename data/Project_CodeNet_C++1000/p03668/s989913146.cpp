#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cmath>
const int MaxN = 1e6;
using namespace std;
int pre[2 * MaxN + 5] , last[MaxN + 5] , other[MaxN + 5];
int all , n , res[MaxN + 5];
void Build(int u , int v){
	pre[++all] = last[u];
	last[u] = all;
	other[all] = v;
}
void dfs(int x , int fa){
	int ed = last[x];
	while(ed != -1){
		int dr = other[ed];
		if(dr != fa){
			dfs(dr , x);
			res[x] ^= res[dr] + 1;
		}
		ed = pre[ed];
	}
}
int main()
{
	while(~scanf("%d" , &n)){
		all = -1;
		memset(last , -1 , sizeof(last));
		memset(res , 0 , sizeof(res));
		for(int i = 1;i <= n - 1;i++){
			int u , v;
			scanf("%d%d" , &u , &v);
			Build(u , v); Build(v , u);
		}
		dfs(1 , 0);
		if(res[1]) printf("Alice\n");
		else printf("Bob\n");
	}
}