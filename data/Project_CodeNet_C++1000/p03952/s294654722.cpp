#include<bits/stdc++.h>
using namespace std;
#define il inline
#define gc getchar()
#define mp make_pair
#define P pair<int,int>
#define ri register int
#define rb register bool
#define rc register char
#define t(i) edge[i].to
#define w(i) edge[i].wei
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)
#define e(i,x) for(ri i=head[x];i;i=edge[i].nxt)

const int N=2e5+10;
int n,x,a[N],tmp;
bool vis[N];

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch<'0' || ch>'9'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}

int main()
{
	n=read();x=read();if(x==1 || x==n*2-1)return printf("No\n"),0;printf("Yes\n");
	if(x==2){a[n]=2;a[n+1]=1;tmp=2;n=n*2-1;rp(i,1,n)if(!a[i])a[i]=++tmp;rp(i,1,n)printf("%d\n",a[i]);return 0;}
	a[n]=x;a[n+1]=x+1;a[n-1]=x-1;a[n+2]=x-2;vis[x]=vis[x+1]=vis[x-1]=vis[x-2]=1;
	tmp=1;n=n*2-1;rp(i,1,n)if(!a[i]){while(vis[tmp])++tmp;a[i]=tmp;vis[tmp]=1;}rp(i,1,n)printf("%d\n",a[i]);
	return 0;
}
