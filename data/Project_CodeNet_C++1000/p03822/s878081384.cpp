#include<bits/stdc++.h>
using namespace std;
int n,f[100009];
vector<int>son[100009];
void dfs(int x) {
	if(son[x].empty()) return;
	for(int i=0;i<son[x].size();i++) dfs(son[x][i]);
	vector<int>tmp;
	for(int i=0;i<son[x].size();i++) tmp.push_back(f[son[x][i]]);
	sort(tmp.begin(),tmp.end());
	int mx=0;
	for(int i=0;i<tmp.size();i++) mx=max(mx,tmp[i]+(int)tmp.size()-i);
	f[x]=mx;
}
int main() {
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		int x;
		scanf("%d",&x);
		son[x].push_back(i);
	}
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}