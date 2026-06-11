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
int n,a[N],l,r;
bool b[N];

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch<'0' || ch>'9'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}
il bool chck(){rp(i,2,n)if(b[i]==b[i-1])return 0;return 1;}
il bool check(ri dat)
{
	rp(i,1,n)b[i]=(a[i]>dat);ri mid=(n+1)>>1;if(chck())return b[1];
	rp(i,1,mid-1){if(b[mid+i]==b[mid+i-1])return b[mid+i];if(b[mid-i]==b[mid-i+1])return b[mid-i];}
}

int main()
{
	//freopen("2165.in","r",stdin);freopen("2165.out","w",stdout);
	n=r=read()*2-1;rp(i,1,n)a[i]=read();
	while(l<r){ri mid=(l+r)>>1;if(!check(mid))r=mid;else l=mid+1;}printf("%d",l);
	return 0;
}
