#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
LL read() {
	LL q=0,w=1;char ch=' ';
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+(LL)(ch-'0'),ch=getchar();
	return q*w;
}
const int N=100005;
int n,m,to[60][N];LL K,bin[60],p[N],d[N],a[N],b[N];
int work(int x) {
	for(RI i=59;i>=0;--i) if(K&bin[i]) x=to[i][x];
	return x;
}
int main()
{
	n=read();
	for(RI i=1;i<=n;++i) p[i]=read(),d[i]=p[i]-p[i-1];
	m=read(),K=read();
	for(RI i=1;i<=n;++i) a[i]=i;
	for(RI i=1;i<=m;++i) {int x=read();swap(a[x],a[x+1]);}
	for(RI i=1;i<=n;++i) to[0][a[i]]=i;
	bin[0]=1;for(RI i=1;i<=59;++i) bin[i]=bin[i-1]<<1;
	for(RI j=1;j<=59;++j)
		for(RI i=1;i<=n;++i) to[j][i]=to[j-1][to[j-1][i]];
	for(RI i=1;i<=n;++i) a[i]=work(i);
	for(RI i=1;i<=n;++i) b[a[i]]=i;
	for(RI i=1;i<=n;++i)
		p[i]=p[i-1]+d[b[i]],printf("%lld.0\n",p[i]);
	return 0;
}