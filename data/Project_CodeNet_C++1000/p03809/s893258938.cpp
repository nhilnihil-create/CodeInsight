#include<bits/stdc++.h>
#define go(i,x,a) for(int i=a;i<x;i++)
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],head[maxn],k,in[maxn],rt;
int tl;
bool ans=0;
ll up[maxn],q[maxn];

struct edd{
	int nxt,v;
}e[maxn*2];

inline void add(int a,int b){
	e[k].v=b; e[k].nxt=head[a]; head[a]=k++;
	e[k].v=a; e[k].nxt=head[b]; head[b]=k++;
}

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

void dfs(int u,int fa){
	if(ans) return;
	if(in[u]==1){
		up[u]=a[u];return;
	}
	ll d,big=0;tl=0;
	for(int i=head[u];i+1;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		if(ans) return;
		up[u]+=up[v],big=max(big,up[v]);//算出石头最多的子节点 
	}
	//我们在“子节点自行解决的时候 ”，子节点总权值-2，父节点权值-1 
	if(big>up[u]-big) d=up[u]-big;
	else d=up[u]/2;//能够“自行解决 ”的数量 
	if(a[u]>up[u]){ans=1;return;}
	if(up[u]-a[u]>d){ans=1;return;}//如果需要“自行解决 ”的数量大于能够“自行解决 ”的数量，不成立 
	up[u]-=2*(up[u]-a[u]); //减去要“自行解决 ”的数量
}

int main(){
	//freopen("input.txt","r",stdin);
	memset(head,-1,sizeof(head)); k=0;
	n=rd(); int x,y;
	go(i,n+1,1) a[i]=rd();
	go(i,n,1){ x=rd(); y=rd(); add(x,y); in[x]++; in[y]++; }
	if(n==2){
		if(a[1]!=a[2]) printf("NO");
		else puts("YES");
	}
	else{
		go(i,n+1,1){
			if(in[i]>1){
				x=i;break;
			}
		}
		dfs(x,0);
		if(ans||up[x]) printf("NO");
		else puts("YES");
	}
	return 0;
} 