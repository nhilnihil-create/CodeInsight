#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int n,cnt = 1;
struct node{
	int next;
	int to;
	node():next(-1){
	}
}e[N<<1];
int head[N];
int c[N];
void addEdge(int from,int to){
	e[cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt++;
};
void dfs(int u,int pre,int s,int &ok){
	if(u == n){
		ok = s;
		return;
	}
	int tmp = head[u];
	while(tmp!=0){
		if(ok)break;
		if(e[tmp].to!=pre)
			dfs(e[tmp].to,u,s+1,ok);
		tmp = e[tmp].next;
	}
	if(ok){
		if(u!=1&&s<=ok/2)c[u] = 1;
		if(u!=n&&s>ok/2)c[u]=-1;
	}
	return;
}
void DFS(int u,int pre,int k,int &tot){
	if(c[u] == -k)return;
	tot++;
	int tmp = head[u];
	while(tmp!=0){
		if(e[tmp].to!=pre)DFS(e[tmp].to,u,k,tot);
		tmp = e[tmp].next;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	int ok = 0;
	c[1] = 1;
	c[n] = -1;
	dfs(1,-1,0,ok);
	
	int s1 = 0,s2 = 0;
	DFS(1,-1,1,s1);
	DFS(n,-1,-1,s2);
	if (s1-s2>=1)
         printf("Fennec\n");
     else
         printf("Snuke\n");
	return 0;
}
