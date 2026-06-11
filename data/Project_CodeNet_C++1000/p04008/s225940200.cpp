#include <map>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

int to[100005],nxt[100005],hed[100005] = {0},ec = 0;
void add_edge(int f,int t){
	ec ++; to[ec] = t; nxt[ec] = hed[f]; hed[f] = ec;
}

int n,k,a[100005],ans = 0;

int dfs(int v,int dep){
	int tmp = dep;
	for(int i = hed[v];i;i = nxt[i]){
		tmp = max(tmp,dfs(to[i],dep + 1));
	}
	if(a[v] != 1 && tmp - dep == k - 1){
		a[v] = 1;
		ans ++;
		return -1;
	}
	return tmp;
}

int main(){
	scanf("%d %d",&n,&k);
	scanf("%d",&a[1]); if(a[1] != 1) ans ++; a[1] = 1;
	for(int i = 2;i <= n;i ++){
		scanf("%d",&a[i]);
		add_edge(a[i],i);
	}
	dfs(1,0);
        cout << ans << endl;
	return 0;
}