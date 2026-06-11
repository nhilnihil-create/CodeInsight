#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2005,maxe=maxn<<1;
int n,K,u[maxn],v[maxn],ans,Q[maxn],dst[maxn];
int e,lnk[maxn],nxt[maxe],son[maxe];
bool vis[maxn];
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0;bool f=0;char ch=nc();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=nc();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=nc();
	return f?-ret:ret;
}
void BFS(int x,int y){
	memset(vis,0,sizeof vis);
	int hed=0,til=0;
	if(x) vis[x]=1,Q[++til]=x,dst[x]=0;
	if(y) vis[y]=1,Q[++til]=y,dst[y]=0;
	while(hed^til)
	for (int i=lnk[Q[++hed]];i;i=nxt[i])
	if(!vis[son[i]])
	vis[son[i]]=1,Q[++til]=son[i],dst[son[i]]=dst[Q[hed]]+1;
	int now=0;
	for (int i=1;i<=n;i++) if(dst[i]<=K) now++;
	if(now>ans) ans=now;
}
inline void add_e(int x,int y){son[++e]=y;nxt[e]=lnk[x];lnk[x]=e;}
int main(){
	n=read(),K=read();
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		add_e(u[i],v[i]),add_e(v[i],u[i]);
	}
	if(K&1){
		K>>=1;
		for (int i=1;i<n;i++) BFS(u[i],v[i]);
	}else{
		K>>=1;
		for (int i=1;i<=n;i++) BFS(i,0);
	}
	printf("%d\n",n-ans);
	return 0;
}