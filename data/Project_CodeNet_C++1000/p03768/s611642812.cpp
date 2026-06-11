#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=100005;
int n,m,tot,js,Q;
int h[N],ne[N<<1],to[N<<1],wk[N],X[N],D[N],C[N],col[N],q[N],dis[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
void work(int x,int d,int c) {
	if(d<=wk[x]) return;
	wk[x]=d;
	if(!col[x]) col[x]=c;
	if(!d) return;
	for(RI i=h[x];i;i=ne[i]) work(to[i],d-1,c);
}
int main()
{
	int x,y;
	n=read(),m=read();
	for(RI i=1;i<=m;++i) x=read(),y=read(),add(x,y),add(y,x);
	Q=read();
	for(RI i=1;i<=Q;++i) X[i]=read(),D[i]=read(),C[i]=read();
	for(RI i=1;i<=n;++i) wk[i]=-1;
	for(RI i=Q;i>=1;--i) work(X[i],D[i],C[i]);
	for(RI i=1;i<=n;++i) printf("%d\n",col[i]);
	return 0;
}