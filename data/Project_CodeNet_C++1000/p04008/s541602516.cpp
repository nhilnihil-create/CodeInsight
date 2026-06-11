#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,K,ans,e,lnk[maxn],nxt[maxn],son[maxn],dep[maxn];
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
inline void add_e(int x,int y){son[++e]=y;nxt[e]=lnk[x];lnk[x]=e;}
void DFS(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i])
	DFS(son[i],x),dep[x]=max(dep[x],dep[son[i]]);
	if(++dep[x]==K) ans+=x!=1&&fa!=1,dep[x]=0;
}
int main(){
	n=read(),K=read();
	if(read()^1) ans++;
	for (int i=2;i<=n;i++) add_e(read(),i);
	DFS(1,-1);printf("%d\n",ans);
	return 0;
}