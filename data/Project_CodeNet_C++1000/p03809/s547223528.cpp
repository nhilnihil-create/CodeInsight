#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
typedef long long LL;
const int N=100005;
int n,tot,h[N],ne[N<<1],to[N<<1],du[N];
LL a[N],f[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
void dfs(int x,int las) {
	if(du[x]==1) {f[x]=a[x];return;}
	LL orzabs=0,p,mx=0;
	for(RI i=h[x];i;i=ne[i]) {
		if(to[i]==las) continue;
		dfs(to[i],x),f[x]+=f[to[i]],mx=max(mx,f[to[i]]);
	}
	if(mx>f[x]-mx) p=f[x]-mx;
	else p=f[x]/2;
	if(f[x]<a[x]) {puts("NO");exit(0);}
	if(f[x]-a[x]>p) {puts("NO");exit(0);}
	f[x]-=(f[x]-a[x])*2LL;
}
int main()
{
	int x,y;
	n=read();
	for(RI i=1;i<=n;++i) a[i]=read();
	if(n==2) {
		if(a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for(RI i=1;i<n;++i)
		x=read(),y=read(),add(x,y),add(y,x),++du[x],++du[y];
	for(RI i=1;i<=n;++i) if(du[i]>1) {
		dfs(i,0);
		if(f[i]) puts("NO");
		else puts("YES");
		return 0;
	}
	return 0;
}