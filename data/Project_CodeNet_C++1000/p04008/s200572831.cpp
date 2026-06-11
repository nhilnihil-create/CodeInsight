#include <cstdio>
#include <vector>

#define PB push_back

using namespace std;

const int N = 1e5 + 500;

int n, K, sol, par[N];
vector < int > r[N];

int dfs(int x){
	int dep = 0;
	for(int y : r[x])
		dep = max(dep, dfs(y));
	if(dep == K - 1 && par[x] != 1)
		dep = -1, sol++;
	return dep + 1;
}

int main(){
	scanf("%d%d%d", &n, &K, &sol);
	sol = (sol != 1); par[1] = 1;
	for(int i = 2;i <= n;i++){
		int x; scanf("%d", &x);
		r[x].PB(i); par[i] = x;
	}
	dfs(1);
	printf("%d\n", sol);
}
