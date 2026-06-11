#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
vector<int>g[100004];
vector<int>get_[100004];
bool cmp(int a,int b){
	return a>b;
}
int dfs(int x){
	int res=0;
	for (int i=0;i<g[x].size();i++)
		get_[x].push_back(dfs(g[x][i]));
	sort (get_[x].begin(),get_[x].end(),cmp);
	for (int i=0;i<get_[x].size();i++) res=max(res,get_[x][i]+i+1);
	return res;
}
int main(){
	read(n);
	for (int i=2;i<=n;i++){
		int p;read(p);
		g[p].push_back(i);
	}
	write(dfs(1));
}