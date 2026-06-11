/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int Ri(){
	register int r=0,c=getchar();
	while(c<'0' || '9'<c) c=getchar();
	while('0'<=c && c<='9') r=(r<<1)+(r<<3)+c-'0',c=getchar();
	return r;
}

const int N=1e5+10;

struct GRAPH{
	int head[N],nxt[N<<1],to[N<<1],du[N],ncnt;
	void AddEdge(int u,int v){
		int p=++ncnt,q=++ncnt;
		du[u]++,du[v]++;
		nxt[p]=head[u],to[p]=v,head[u]=p;
		nxt[q]=head[v],to[q]=u,head[v]=q;
	}
	int operator [](const int &u){return head[u];}
}Gr;

int n;
int val[N];
bool fail;

int DFS(int u,int fa){
	if(Gr.du[u]==1) return val[u];
	long long tot=0;
	int mx=0;
	for(int it=Gr[u];it;it=Gr.nxt[it]){
		int v=Gr.to[it];
		if(v==fa) continue;
		int res=DFS(v,u);
		mx=max(mx,res),tot+=res;
	}
	long long mat=tot-val[u];
	long long mxmat;
	if(tot-mx>=mx) mxmat=tot/2;
	else mxmat=tot-mx;
	if(mat<0 || mxmat<mat || val[u]-mat<0 || (fa==0 && val[u]-mat>0)){
		printf("NO\n");
		exit(0);
	}
	return val[u]-mat;
}
int main(){
	n=Ri();
	for(int i=1;i<=n;i++) val[i]=Ri();
	for(int i=1;i<n;i++) Gr.AddEdge(Ri(),Ri());
	if(n==2){
		printf("%s\n",val[1]==val[2]?"YES":"NO");
		return 0;
	}
	int rt=0;
	for(int i=1;i<=n && !rt;i++)
		if(Gr.du[i]>=2)
			rt=i;
	DFS(rt,0);
	printf("YES\n");
	return 0;
}