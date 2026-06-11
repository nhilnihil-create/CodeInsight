#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int n, a;
vector<int> G[MX];
int dfs(int t){
	int sz = (int)G[t].size(), ret = 0;
	vector<int> dep(sz);
	rep(i,sz) dep[i] = dfs(G[t][i]);
	sort(dep.begin(), dep.end());
	rep(i,sz) ret = max(ret, dep[i]+sz-i);
	return ret;
}
int main(){
	scanf("%d", &n);
	rep(i,n-1){
		scanf("%d", &a);
		G[a-1].push_back(i+1);
	}
	printf("%d\n", dfs(0));
}