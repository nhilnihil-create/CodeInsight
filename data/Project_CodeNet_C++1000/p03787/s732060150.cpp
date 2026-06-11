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
const int N=100005,M=200005;
int n,m,tot,js,k1,k2,k3;LL ans;
int h[N],ne[M<<1],to[M<<1],col[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
int dfs(int x,int c) {
	col[x]=c;int re=1;++js;
	for(RI i=h[x];i;i=ne[i])
		if(!col[to[i]]) {if(!dfs(to[i],3-c)) re=0;}
		else if(col[to[i]]!=3-c) re=0;
	return re;
}
int main()
{
	int x,y;
	n=read(),m=read();
	for(RI i=1;i<=m;++i) x=read(),y=read(),add(x,y),add(y,x);
	for(RI i=1;i<=n;++i) {
		if(col[i]) continue; js=0;
		if(dfs(i,1)) {
			if(js==1) ++k3;
			else ++k1;
		}
		else ++k2;
	}
	ans=2LL*k3*(n-k3)+1LL*k3*k3+2LL*k1*k1+2LL*k1*k2+1LL*k2*k2;
	printf("%lld\n",ans);
	return 0;
}