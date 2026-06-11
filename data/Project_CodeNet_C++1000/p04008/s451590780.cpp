#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (100010)

int n;
vector<int> e[N];
int parent[N];
int depth[N];
int ans, k;



int dfs(int v, int p){
	int x;
	int re = 0;

	f(i, e[v].size()){
		if (e[v][i] != p){
			x = dfs(e[v][i], v);
			re = max(re, x);
		}
	}
		re++;
		if (re >= k&&p!=0&&v!=0){
			ans++;
			re = 0;
		}
	return re;
}


int main(void){
	int x, y;
	int q;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, n){
		scanf("%d", &x);
		if (i == 0){
			if (x != 1)ans++;
		}
		else{
			e[i].push_back(x - 1);
			e[x - 1].push_back(i);
		}
	}
	dfs(0,-1);
	printf("%d\n", ans);
	return 0;
}
