#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,m;
vector <int> e[N],a1,a2;
int vis[N];
void dfs(int x,vector <int> &a){
	vis[x]=1;
	a.push_back(x);
	for (auto y : e[x])
		if (!vis[y])
			return dfs(y,a);
}
int main(){
	n=read(),m=read();
	int k1,k2;
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
		if (i==1)
			k1=a,k2=b;
	}
	vis[k1]=vis[k2]=1;
	dfs(k1,a1);
	dfs(k2,a2);
	reverse(a1.begin(),a1.end());
	cout << (int)(a1.size()+a2.size()) << endl;
	for (auto x : a1)
		cout << x << " ";
	for (auto x : a2)
		cout << x << " ";
	return 0;
}