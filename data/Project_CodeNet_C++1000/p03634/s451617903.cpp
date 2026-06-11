#include<bits/stdc++.h>
//树链剖分 模板题 
using namespace std;
const int N=4e5+10;
struct node{//链式前向星 
	int next;
	int from;
	int to;
	int v;
}edge[N];
long long dep[N];//节点深度
int top[N];//当前链顶端节点编号
int son[N];//重儿子编号
int siz[N];//子树大小
int fa[N];//父亲节点编号
int id[N];//新编号
int w[N];
 
int cnt;//dfs_clock/dfs序 
int base,d[N],t,head[N],edge_num,vis[N];
void add(int x,int y,int z){
	edge[++edge_num].to=y;
	edge[edge_num].v=z;
	edge[edge_num].next=head[x];
	head[x]=edge_num;
}
long long sum=0;
#define il inline
il void dfs1(int x,int f){//x当前节点 f父亲 deep深度
	//标记每个点的深度 
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(y==f)continue;//若为父亲则continue
		sum+=edge[i].v;
		dep[y]=sum;
		dfs1(y,x);//dfs其儿子 
		sum-=edge[i].v;
		siz[x]+=siz[y];//回溯累加儿子数加到它身上 
	} 	
}
int main(){
	int n;
	cin>>n;
	int v,u,z;
	for(int i=1;i<=n-1;++i){
		cin>>u>>v>>z;
		add(u,v,z);
		add(v,u,z);
	}
	int q,k;
	cin>>q>>k;
	dfs1(k,0);
	int l,r;
	while(q--){
		cin>>l>>r;
		cout<<dep[l]+dep[r]<<endl;
	}
	return 0;
} 
